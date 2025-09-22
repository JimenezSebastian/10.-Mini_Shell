#include "../include/minishell.h"

void print_commands(t_command *cmd)
{
    printf("Parsed Commands:\n");
    while (cmd) {
        printf("Command:\n");
        for (int i = 0; cmd->argv[i]; i++) {
            printf("  Arg: %s\n", cmd->argv[i]);
        }
        while (cmd->redir)
        {
            printf("  Redirection: %s\n File: %s\n", cmd->redir->type, cmd->redir->file);
            cmd->redir = cmd->redir->next;
        }
        cmd = cmd->next;
    }
}

void prints_token(char **tokens)
{
    printf("Tokens:\n");
    for (int i = 0; tokens[i]; i++)
        printf("[%s]\n", tokens[i]);
}

void ft_pruebas(t_memory mem)
{
    prints_token(mem.tokens); // T
	print_commands(mem.commands); // T
}