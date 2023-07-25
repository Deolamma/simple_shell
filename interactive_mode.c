#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * interactive_mode - This mode user enters command from inside our code
 */
void interactive_mode(void)
{
	char **cmds;
	char *line;
	int status;

	do {
		write(STDOUT_FILENO, "$ ", 3);
		line = read_input();
		cmds = _tokenize(line);
		status = process_handler(cmds);
	free(line);
	free(cmds);
	} while (status);
}

