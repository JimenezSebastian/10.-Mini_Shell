#include "../include/minishell.h"

volatile sig_atomic_t g_signal = 0;

void	ft_setup_signals(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_quit;
    
	sigemptyset(&sa_quit.sa_mask);
	sa_quit.sa_handler = &ft_sigquit_handler;
	sa_quit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &sa_quit, NULL);

    sigemptyset(&sa_int.sa_mask);
    sa_int.sa_handler = &ft_sigint_handler;
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL);
}

void	ft_sigquit_handler(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\b\b  \b\b", 6);
}

void	ft_sigint_handler(int signum)
{
	(void)signum;
	g_signal = SIGINT;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_default_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}