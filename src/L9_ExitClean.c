#include "../include/minishell.h"

void free_commands(t_command *cmd) 
{
    while (cmd) 
    {
        t_command *temp = cmd;
        for (int i = 0; cmd->argv[i]; i++) 
        {
            free(cmd->argv[i]);
        }
        free(cmd->argv);
        if (cmd->redir) 
        {
            free(cmd->redir->type);
            free(cmd->redir->file);
            free(cmd->redir);
        }
        cmd = cmd->next;
        free(temp);
    }
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void ft_controller_free(t_memory mem)
{
    if (mem.tokens)
		ft_free_array(mem.tokens);
	if (mem.commands)
		free_commands(mem.commands);
	if (mem.input)
		free(mem.input);
	if (mem.my_env)
		free_env(mem.my_env);
}