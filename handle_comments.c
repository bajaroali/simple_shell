#include "shell.h"

/**
 * handle_comments -  function to handle comments in the shell
 * @input: stores the user input
 *
 */
void handle_comments(char *input)
{
	/*Find the index of the '#' symbol in the input string*/
	char *comment_start = strchr(input, '#');
	/**
	 * If a '#' symbol is found, replace it with a null
	 * terminator '\0' to truncate the input at the comment
	 */
	if (comment_start != NULL)
	{
		*comment_start = '\0';
	}
}
