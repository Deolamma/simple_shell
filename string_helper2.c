#include "shell.h"
/**
 * _strchr - Find the first occurrence of a character in a string
 * @str: Pointer to the null-terminated string to search
 * @ch: The character to find in the string
 * Return: Pointer to the first occurrence of 'ch' in 'str'
 */
const char *_strchr(const char *str, int ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
