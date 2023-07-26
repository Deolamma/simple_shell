#include "shell.h"
/**
 * err_handler - handles errors
 * @message: message to be displayed on stdout
 * @line: already allocated memory
 * @status: exit status (failure or success)
 */
void err_handler(char *message, char *line, int status)
{
	perror(message);
	free(line);
	exit(status);
}

/**
 * read_frm_stream - receives command from stream
 * Return: returns a pointer to where command read is stored
 */
char *read_frm_stream(void)
{
	int bufsize = BUFFSIZ, character, i = 0;
	char *line = malloc(sizeof(char) * bufsize);

	if (line == NULL)
	{
		perror("allocation failed");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		} else if (character == '\n')
		{
			line[i] = '\0';
			break;
		}
		line[i] = character;
		i++;
		if (i >= bufsize)
		{
			bufsize *= 2;
			line = realloc(line, bufsize);
			if (line == NULL)
			{
				err_handler("Reallocation failed", line, EXIT_FAILURE);
			}
		}
	}
	return (line);
}
