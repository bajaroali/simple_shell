#include "shell.h"

/**
 * print_error_message - prints the error message
 * @cmd: The command passed
 * exit with status failure
 */
void print_error_message(char *cmd)
{
	char *f_err;

	char *s_err;

	f_err = "Command '";
	write(STDERR_FILENO, f_err, strlen(f_err));
	write(STDERR_FILENO, cmd, strlen(cmd));
	s_err = "' not found\n";
	write(STDERR_FILENO, s_err, strlen(s_err));
	exit(EXIT_FAILURE);
}

