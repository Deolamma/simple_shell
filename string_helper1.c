#include "shell.h"
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
/**
 * _strdup - duplicates a string
 * @s: string to be duplicated
 * Return: returns a pointer to the duplicated string
 */
char *_strdup(char *s)
{
	char *dup_str = NULL;
	int s_len;
	int i;

	if (!s)
		return (NULL);
	s_len = _strlen(s);
	dup_str = malloc(sizeof(char) * (s_len + 1));
	if (!dup_str)
		return (NULL);
	for (i = 0; i < s_len; i++)
	{
		dup_str[i] = s[i];
	}
	dup_str[s_len] = '\0';
	return (dup_str);
}
/**
 * _strdup_arr - duplicating a array of characters
 * @src: source array to be duplicated
 * Return: returns a duplicated array of source onSuccess
 */
char **_strdup_arr(char **src)
{
	size_t i, j, num_elem = 0;
	char **dup_arr;

	if (!src)
		return (NULL);
	while (!(src[num_elem]))
	{
		num_elem++;
	}
	dup_arr = malloc(sizeof(char *) * (num_elem + 1));
	if (!dup_arr)
		return (NULL);

	for (i = 0; i < num_elem; i++)
	{
		/* duplicate the string in src array i to dup_arr */
		dup_arr[i] = _strdup(src[i]);
		if (!dup_arr[i])
		{
		/* free memory of each string already alloc if copy fails */
			for (j = 0; j < i; j++)
				free(dup_arr[j]);
			/* free the array itself */
			free(dup_arr);
			return (NULL);
		}
	}
	dup_arr[num_elem] = '\0';
	return (dup_arr);
}
/**
 * _putchar - prints one char at a time
 * @c: character to be printed
 * Return: the character the value that has been written or EOF
 */
int _putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

