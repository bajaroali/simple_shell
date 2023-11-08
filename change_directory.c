#include "shell.h"

/**
 * change_directory - changes the directory
 * @dir: arg passed to the cd command
 */
void cd_builtin(char *dir)
{
	char *home;

	if (dir == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			perror("cd: HOME environment is not yet set.\n");
		}
		else
		{
			if (chdir(home) != 0)
			{
				perror("Could not change the directory.");
			}
		}
	}
	else
	{
		if (chdir(dir) != 0)
		{
			perror("Could not change the directory.");
		}
	}
}

