#include "shell.h"
/**
 * read_input - reads the command or text written to the terminal
 * Return: returns the string inputted by user
 */
char *read_input()
{
	char *line = NULL;
	size_t buffsize = 0;

	if (getline(&line, &buffsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		} else
		{
			free(line);
			perror("Unable to read input");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

