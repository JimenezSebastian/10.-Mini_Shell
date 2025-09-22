#include "../include/minishell.h"

char	*ft_readline(void)
{
	char	*input;

    input = NULL;
	while (!input)
	{
		input = readline("minishell> ");
		if (ft_strlen(input) > 0)
        {
            add_history(input);
            return (input);
        }
        input = NULL;
	}
    return (NULL);
}

int	main(int argc, char **argv, char **env) // Argumentos por orden y posicion 
{
	t_memory	mem;
	(void)argc;
	(void)argv;
	
	ft_setup_signals();
	mem.my_env = ft_duplicate_env(env);
	if (!mem.my_env)
		return (perror("Failed to duplicate env"), 1);

	while (1)
	{
		mem.input = ft_readline();
		// mem.input = ft_expansion();
		mem.tokens = ft_tokenize(mem.input);
		mem.commands = ft_parse_tokens(mem.tokens);
		//ft_pruebas(mem);
		while (1)
		{
			mem.unity = ft_redir_var_packer(mem.commands);
			if (mem.commands)
			{
				if (ft_builtin_verify(mem.commands, &mem.my_env))
					ft_execute_command(mem.commands, env, mem.unity);
			}
			if (mem.commands->next)
				mem.commands = mem.commands->next;
			else
				break;
		}
	}
}



