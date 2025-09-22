#include "../include/minishell.h"

int *ft_redir_var_packer(t_command *cmd)
{
    static int  old_pipe = 0;
    int         *zero;
    int         *one;
    int         *unity;
    int         pipefd[2];

    (void)cmd;
    pipe(pipefd);
    if (!old_pipe)
        old_pipe = pipefd[0];
    zero = ft_zero(cmd, old_pipe, pipefd[1]); // Lugar de donde proviene la informacion
    one = ft_one(cmd, pipefd[1]); // Lugar a donde va la informacion
    unity = malloc(4 * sizeof(int));
    unity[0] = zero[0];
    unity[1] = zero[1];
    unity[2] = one[0];
    unity[3] = one[1];
    return (unity);
}

int *ft_zero(t_command *cmd,int old_pipe,int pipefd)
{
    t_command   *head;
    int         *pack;
    int         fd;
    char        *line;

    pack = malloc(2 * sizeof(int));
    head = cmd;     
    pack[0] = 0; 
    pack[1] = 0;
    (void)old_pipe;
    // if (cmd->redir)
    //     pack[0] = old_pipe;
    while (cmd->redir)
    {
        if (ft_strncmp(cmd->redir->type, "<<", 2)) 
            line = deploy_heredoc(cmd->redir->file);
        cmd->redir = cmd->redir->next;
        if(!cmd->redir)
            write(pipefd, line, ft_strlen(line));
        free(line);
    }
    cmd = head;
    while (cmd->redir)
    {
        close(fd);
        if (ft_strncmp(cmd->redir->type, "<", 1))
            fd = handle_input_redirection(cmd->redir->file);
        cmd->redir = cmd->redir->next;
    }
    cmd = head;
    while (cmd->redir) 
    {
        if (ft_strncmp(cmd->redir->type, "<<", 2))
            pack[0] = pipefd; 
        if (ft_strncmp(cmd->redir->type, "<", 1))
            pack[0] = fd;
        cmd->redir = cmd->redir->next;
    }
    return (pack);
}

int *ft_one(t_command *cmd, int pipefd)
{
    int         *pack;
    int         fd;

    pack = malloc(2 * sizeof(int)); 
    pack[0] = 1;
    pack[1] = 1;
    if (cmd->next)
        pack[0] = pipefd;
    while (cmd->redir)
    {
        if (ft_strcmp(cmd->redir->type, ">") == 0 && cmd->redir->file)
            fd = handle_output_redirection(cmd->redir->file);
        else if (ft_strcmp(cmd->redir->type, ">>") == 0 && cmd->redir->file)
            fd = handle_append_redirection(cmd->redir->file);
        cmd->redir = cmd->redir->next;
        pack[2] = fd;
    }
    return (pack);
}

int handle_input_redirection(const char *filename)
{    
    int fd_in;
    fd_in = open(filename, O_RDONLY);

    if (fd_in < 0)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    return (fd_in);
}

int handle_output_redirection(const char *filename)
{
    int fd_out;

    fd_out = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd_out < 0)
    {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }
    return (fd_out);
}

int handle_append_redirection(const char *filename)
{
    int fd_append;

    fd_append = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd_append < 0)
    {
        perror("Error opening append file");
        exit(EXIT_FAILURE);
    }
    return (fd_append);
}

char  *deploy_heredoc(const char *delimiter)
{
    size_t  len;
    int     pipe_fd[2];
    char    *line;
    int     cont;

    cont = 0;
    line = NULL;
    len = 0;
    pipe(pipe_fd);
    while (getline(&line, &len, stdin) != -1) 
    {
        printf("heredoc> ");
        if (ft_strcmp(line, delimiter) == 0)
            break;
        cont += ft_strlen(line);
        write(pipe_fd[1], line, cont);
    }
    line = malloc(cont + 1);
    read(pipe_fd[0], line, cont);
    (close (pipe_fd[0]), close (pipe_fd[1]));
    return (line);
}
