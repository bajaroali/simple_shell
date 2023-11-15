#include "shell.h"

/**
 * concatenate_strings - concatenates strings
 * @dest: string
 * @src: string
 * Return: 0  success
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

