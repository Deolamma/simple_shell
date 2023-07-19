#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
/**
 * str_tok - Splits a string into tokens
 * @str: String to be broken down into tokens
 * @delim: string to encounter for split to occur
 * Return: a pointer to the split strings
 */
char *str_tok(char *str, const char *delim)
{
	static char *str_store;
	char *token;
	int i = 0;
	int d_len;

	if (!delim)
		return (NULL);
	if (str)
	{
		str_store = str;
	} else
	{
		if (!str_store || !(*str_store))
		return (NULL);
	}
	token = str_store;
	d_len = _strlen(delim);
	while ((*str_store) && (i != d_len))
	{
		/* shift position if current char is not a delimiter */
		while ((*str_store) && ((*str_store) != (*delim)))
			str_store++;
		 /* Check if it is the cmplete delimiter say "STOP" and not "ST" */
		while ((*str_store) && (str_store[i] == delim[i]) && (i < d_len))
			i++;
		/*
		 * if it's actually a delimiter set the current char to '\0'
		 * Increment by the length of delimiter
		 */
		if (i == d_len)
		{
			(*str_store) = 0;
			str_store += d_len;
		} else
			str_store++;
	}
	return (token);
}
/**
 * _getline - my custom getline fxn
 * @line: address of where character array will be stored
 * @n: address of where number of bytes to be written is stored
 * @stream: the source of where bytes are to be read from
 * Return: returns number of bytes read excluding '\0' or -1 on error
 */
ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	static char buff[BUFFSIZ];
	static size_t buff_size;
	size_t nb_read = 0, line_len = 0;

	if (line == NULL || n == NULL)
		return (-1);
	if ((*line) == NULL || *n == 0)
	{
		(*n) = BUFFSIZ;
		(*line) = malloc(*n);
		if ((*line) == NULL)
			return (-1);
	}
	buff_size = 0;
	while (1)
	{
		if (buff_size >= nb_read)
		{
			/* FUTURE OPTIMIZATION */
			/* if *n properly reflect it in read system call */
			nb_read = read(fileno(stream), buff, BUFFSIZ);
			if (nb_read == (size_t)-1)
				return (-1);
		}
		(*line)[line_len] = buff[buff_size];
		line_len++;
		buff_size++;
		if ((*line)[line_len - 1] == '\n')
			break;
		if (line_len >= (*n))
		{
			(*n) *= 2;
			(*line) = realloc(*line, (*n));
			if ((*line) == NULL)
				return (-1);
		}
	}
	(*line)[line_len] = '\0';
	return ((ssize_t)line_len);
}
