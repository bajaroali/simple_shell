#include "shell.h"

/**
 * start_new_program - a function that starts a new program, child program
 * @args: The command argument passed as input
 * Return: 0 success
 */
int start_new_program(char *args[])
{

	char *line = NULL;

	int pid;

	char *path_command;

	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Forking Failed");
		free(line);
		return (-1);
	}
	else if (pid == 0)
	{
		path_command = check_path(args[0]);
		if (path_command != NULL)
		{
			execve(path_command, args, environ);
			free(line);
			print_error_message(args[0]);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}

