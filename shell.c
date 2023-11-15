#include "shell.h"

/**
 * print_prompt - Print prompt in interactive mode
 * Return: void
 */
void print_prompt(void)
{
	char *prompt = "$ ";
	int char_write;

	char_write = write(STDOUT_FILENO, prompt, strlen(prompt));
	if (char_write == -1)
	{
		perror("Write error");
		exit(1);
	}
}

/**
 * read_input - Reads user input from stdin
 * @line: Pointer  input line
 * @len: Pointer to length of  input line
 * Return: Number of characters
 *
 */
ssize_t read_input(char **line, size_t *len)
{
	ssize_t char_read = getline(line, len, stdin);

	if (char_read == -1)
	{
		if (feof(stdin))
		{
			free(*line);
			exit_builtin();
		}
		else
		{
			perror("Error reading input\n");
			free(line);
			exit(-1);
		}
	}

	return (char_read);
}

/**
 * main -function to read user input
 * Return: 0 on success
 */
int main(void)
{
	ssize_t char_read;
	size_t len = 0;
	char *line = NULL;
	int is_interactive = isatty(STDIN_FILENO);

	signal(SIGINT, signal_handler);
	while (1)
	{
		if (is_interactive)
		{
			print_prompt();
		}
		fflush(stdout);
		char_read = read_input(&line, &len);

		if (char_read == 1)
		{
			continue;
		}
		else
		{
			tokenize(line);
		}
	}
	free(line);
	return (0);
}

