#include "shell.h"
/**
 * _strcmp - This function compares two strings
 * @str1: The first string to be compared
 * @str2: The second string to be compared
 * Return: 0 if both strings are equal
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
/**
 * _strcpy - This copies files from source to destination
 * @destination: Pointer to the destination buffer
 * @source: Pointer to the source string to be copied
 * Return: Pointer to the destination buffer
 */
char *_strcpy(char *destination, const char *source)
{
	char *original_destination = destination;
	/* Loop through the source string until the null terminator is found */
	while (*source)
	{
		/* Copy the current character from source to destination */
		*destination = *source;

		/* Move to the next character in both source and destination */
		source++;
		destination++;
	}

	/* Add the null terminator at the end of the copied string */
	*destination = '\0';

	/* Return the pointer to the destination buffer */
	return (original_destination);
}
/**
 * _strcat - Concatenates two strings
 * @destination: Pointer to the destination buffer
 * @source: Pointer to the source string to be appended
 *
 * Return: Pointer to the destination buffer after concatenation
 */
char *_strcat(char *destination, const char *source)
{
	char *original_destination = destination;
	/* Move to the end of the destination string */
	while (*destination)
		destination++;

	/* Append characters from the source string to the destination */
	while (*source)
	{
		*destination = *source;
		source++;
		 destination++;
	}

	*destination = '\0'; /* Don't forget to add the null-terminator at the end */
	return (original_destination);
}
/**
 * _strlen - gets the number of chars in a str..
 * @str: string in which length is to be gotten
 * Return: Number of characters excluding the '\0' byte
 *
 */
size_t _strlen(const char *str)
{
	size_t count = 0;

	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}
/**
 * _strncmp - compares up to n bytes of two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 * Return: returns 0 if up to n bytes are equal
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	/* if either s1 or s2 is NULL */
	/* return 1 if s1 is NOT NULL */
	/* return -1 if s2 is NOT NULL */
	/* the if block can NEVER return 0 */
	if (!s1 || !s2)
		return (s1 ? 1 : (s2 ? -1 : 0));

	for (i = 0; (size_t)i < n; i++)
	{
		if (*s1 != *s2)
			return ((*s1) - (*s2));

		if (*s1 || *s2)
			break;
		s1++;
		s2++;
	}
	return (0);
}
