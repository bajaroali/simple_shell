#include "shell.h"

/**
 * concatenate_strings - concatenator
 * @dest: string
 * @src: string
 * Return: 0 on success
 */
char *concatenate_strings(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

