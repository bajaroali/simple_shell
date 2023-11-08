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
 * handle_signal - a function to handle signals
 * @sig: the number of the signal
 */
void handle_signal(int sig)
{
	char *prompt = "\n$ ";

	(void)sig;
	write(1, prompt, strlen(prompt));
	fflush(stdout);
}

