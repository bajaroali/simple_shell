#include "shell.h"

/**
 * exit_shell - exits the shell
 * exits with 0 for success
 */
void exit_builtin(void)
{
	exit(0);
}

/**
 * signal_handler - a function to handle signals
 * @sig: the number of the signal
 */
void signal_handler(int sig)
{
	char *prompt = "\n$ ";

	(void)sig;
	write(1, prompt, strlen(prompt));
	fflush(stdout);
}

