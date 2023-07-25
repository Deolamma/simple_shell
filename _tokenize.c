#include "shell.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _tokenize - Breaks strings recieved as it's param into tokens
 * @line: string to be tokenized
 * Return: returns an array of strings(tokens or cmds) to be executed
 */
char **_tokenize(char *line)
{
	char **tokens;
	char *token;
	int i = 0, tokens_buff = TOKENS_BUFF;


	tokens = malloc(sizeof(char *) * tokens_buff);
	if (!tokens)
	{
		dprintf(STDERR_FILENO, "Memory allocation failed: _tokenize");
		free(line);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		tokens[i] = token;
		i++;
		if (i >= tokens_buff)
		{
			tokens_buff *= 2;
			tokens = realloc(tokens, sizeof(char *) * tokens_buff);
			if (!tokens)
			{
				dprintf(STDERR_FILENO, "Memory realloc failed: _tokenize");
				free(tokens);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}
	tokens[i] = '\0';
	return (tokens);
}
