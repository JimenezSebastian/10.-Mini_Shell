#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <errno.h>

#define MAX_TOKENS 1024

extern volatile sig_atomic_t g_signal;

typedef struct s_redirection 
{
    char *type; // "<", ">", ">>", "<<"
    char *file;
    struct s_redirection *next; 
} t_redir;

typedef struct s_command 
{
    char **argv;
    t_redir *redir;
    struct s_command *next;
} t_command;

typedef struct s_memory
{
	t_command   *commands;
	char		*input;
	char		**my_env;
	char		**tokens;
	int			*unity;
}	t_memory;

// L0_Sig
void ft_setup_signals(void);
void ft_sigint_handler(int signum);
void ft_sigquit_handler(int signum);
void	ft_default_signals(void);

// L1
// (Expansiones)


// L2 Token
int is_operator(char c);
char *extract_quoted_content(char *input, size_t *i);
char **ft_tokenize(char *input);

// L3_Parse
t_command   *ft_parse_tokens(char **tokens);
t_command   *ft_logic(char **tokens, size_t *i);
t_command   *ft_new_cmd(void);
int         ft_isop(char *tokens);
void        ft_new_redir(t_command **cmd, char *type, char *file);


// L4 Redir
int handle_input_redirection(const char *filename);
int handle_output_redirection(const char *filename);
int handle_append_redirection(const char *filename);
char *deploy_heredoc(const char *delimiter);
int *ft_zero(t_command *cmd, int old_pipe, int pipefd);
int *ft_one(t_command *cmd, int pipefd);
int *ft_redir_var_packer(t_command *cmd);

// L5 Exec 
char **get_path_dirs(char **envp);
char *find_executable(char *cmd, char **path_dirs);
void ft_execute_command(t_command *cmd, char **envp, int *unity);

// L6 Built
int ft_builtin_verify(t_command *cmd, char ***envp);
int ft_echo(char **args);
int ft_cd(char **args, char ***env);
int ft_pwd(void);
int ft_export(char **args, char ***env);
int ft_unset(char **args, char ***env);
int ft_env(char **args, char **env);
int ft_exit(char **args);

// L6 U Built
size_t env_count(char **env);
char **ft_duplicate_env(char **env);
char *getenv_from_env(char **my_env, const char *var);
int setenv_in_env(char ***my_env, const char *var, const char *value);
int unsetenv_in_env(char ***my_env, const char *var);
void free_env(char **my_env);
void print_env_export(char **env);
int  is_valid_identifier(const char *str); 


/* Capas menos operables*/

//L9
void    free_commands(t_command *cmd);
void	ft_free_array(char **array);
void ft_controller_free(t_memory mem);

//Func
void prints_token(char **tokens);
void print_commands(t_command *cmd);
void ft_pruebas(t_memory mem);

// #Comments 
//int is_builtin(const char *cmd);
//int run_builtin(char **args, char ***env);

#endif