#include "shell.h"

/**
 * compare_strings - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: function pointer
 */
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

/**
 * calculate_length - length calculator
 * @str: string
 * Return: length
 */
size_t calculate_length(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}


