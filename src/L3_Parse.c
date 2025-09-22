#include "../include/minishell.h"

t_command *ft_parse_tokens(char **tokens)
{
    t_command   *head;
    t_command   *current;
    t_command   *cmd;
    size_t      i;
    
    (head = NULL, current = NULL, cmd = NULL, i = 0);
    while (tokens[i])
    {
        cmd = ft_logic(tokens, &i);
        if (!head)
            head = cmd;
        else
            current->next = cmd;
        current = cmd;

        if (tokens[i] && !ft_strcmp(tokens[i], "|"))
            ++i;
    }
    return (head);
}

t_command *ft_logic(char **tokens, size_t *i)
{
    t_command   *cmd;
    size_t      arg_c;

    arg_c = 0;
    cmd = ft_new_cmd(); 
    while (tokens[*i] && ft_strcmp(tokens[*i], "|"))
    {
        if (ft_isop(tokens[*i]) && (tokens[*i + 1]))
            (ft_new_redir(&cmd, tokens[*i], tokens[*i + 1]), (*i) += 1);    
        else
            cmd->argv[arg_c++] = tokens[*i];
        (*i)++;
    }
    cmd->argv[arg_c] = NULL;
    return (cmd);
}

t_command *ft_new_cmd(void)
{
    t_command *cmd = malloc(sizeof(t_command));
    cmd->argv = malloc(sizeof(char *) * MAX_TOKENS);
    cmd->redir = NULL;
    cmd->next = NULL;
    return (cmd);
}

int ft_isop(char *tokens)
{
    return ( ft_strcmp(tokens, ">") == 0 || ft_strcmp(tokens, ">>") == 0 
    || ft_strcmp(tokens, "<") == 0 || ft_strcmp(tokens, "<<") == 0);
}

void ft_new_redir(t_command **cmd, char *type, char *file)
{
    t_redir *new = malloc(sizeof(t_redir));
    new->type = type;
    new->file = file;
    new->next = NULL;
    
    if (!(*cmd)->redir) 
       (*cmd)->redir = new;
    else
        (*cmd)->redir->next = new;
    (*cmd)->redir = new;
}
