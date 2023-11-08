#include "shell.h"

/**
 * print_environment - prints the environment
 *
 */
void print_environment(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}
