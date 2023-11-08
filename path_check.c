#include "shell.h"

/**
 * check_path - a function to check for the path
 * @cmd: The command to be checked in the path
 * Return: NULL
*/
char *check_path(char *cmd)
{
	char *path = getenv("PATH");
	char *copy_path = strdup(path);
	char cmd_path[1024];
	char *dir = strtok(copy_path, ":");

	if (copy_path == NULL)
	{	perror("Failed");
		return (NULL);
	}
	while (dir != NULL)
	{
		strcpy(cmd_path, dir);
		if (cmd_path[calculate_length(cmd_path) - 1] != '/')
		{
			strcat(cmd_path, "/");
		}
		concatenate_strings(cmd_path, cmd);
		if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) == 0)
		{
			free(copy_path);
			return (strdup(cmd_path));
		}
		dir = strtok(NULL, ":");
	}
	free(copy_path);
	return (cmd);
}

