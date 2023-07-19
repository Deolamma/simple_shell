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
		status = execute_commands(cmds);

	free(line);
	free(cmds);
	if (status != 1)
		exit(status);
	} while (status);
}

