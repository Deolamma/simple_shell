#include "shell.h"
/**
 * error_handler - frees up memory
 * @cmds: command entered by user
 */
void error_handler(char **cmds)
{
	int i;

	for (i = 0; cmds[i]; i++)
		free(cmds[i]);
	free(cmds);
}
