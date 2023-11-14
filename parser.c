#include "shell.h"

/**
 * tokenize - tokenizes the path
 * @input: The line containing the user input
 * Return: 0 success
 */
int tokenize(char *input)
{
	int index = 0;
	char *tok;
	char *delimiters = " \a\n\t\r";
	char *args[1024];

	tok = strtok(input, delimiters);
	while (tok != NULL)
	{
		args[index] = tok;
		tok = strtok(NULL, delimiters);
		index++;
	}
	args[index] = NULL;
	if (args[0] == NULL)
	{
		return (0);
	}
	if (compare_strings(args[0], "cd") == 0)
	{
		cd_builtin(args[1]);
	}
	else if (compare_strings(args[0], "exit") == 0)
	{
		free(input);
		exit_builtin();
	}
	else if (compare_strings(args[0], "env") == 0)
	{
		print_environment();
	}
	else
	{
		start_new_program(args);
	}
	return (0);
}
