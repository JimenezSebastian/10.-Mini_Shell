#include "../include/minishell.h"

char	**get_path_dirs(char **envp)
{
	char	*path;
	char	**path_dirs;
	int		i;

	path = NULL;
	path_dirs = NULL;
	i = 0;
	// Busca "PATH" en las variables de entorno
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
		i++;
	}
	if (path)
		path_dirs = ft_split(path, ':'); // Divide por ':'
	return (path_dirs); // Array de strings con las rutas
}


char *find_executable(char *cmd, char **path_dirs)
{
    char *full_path;
    char *temp;

    for (int i = 0; path_dirs[i] != NULL; i++)
    {
        temp = ft_strjoin(path_dirs[i], "/");
        full_path = ft_strjoin(temp, cmd);
        free(temp);

        if (access(full_path, X_OK) == 0) // Verifica si es ejecutable
            return full_path;

        free(full_path);
    }

    return NULL; // Comando no encontrado
}

void ft_execute_command(t_command *cmd, char **envp, int *unity)
{
    pid_t pid;
    char **path_dirs;
    char *exec_path;

    if (!cmd || !cmd->argv || !cmd->argv[0])
        fprintf(stderr, "Invalid command\n");
    path_dirs = get_path_dirs(envp);
    exec_path = find_executable(cmd->argv[0], path_dirs);
    if (!exec_path)
        fprintf(stderr, "Command not found: %s\n", cmd->argv[0]);
    pid = fork();
    if (pid < 0)
        perror("fork");
    if (pid == 0)
    {
        ft_default_signals();
        dup2(unity[0], unity[1]);
        dup2(unity[2], unity[3]);
        if (execve(exec_path, cmd->argv, envp) == -1)
            perror("execve"); 
    }
    waitpid(pid, NULL, 0);
    free(exec_path);
    free(path_dirs);
}