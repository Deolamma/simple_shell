#include "shell.h"
/**
 * non_interactive_mode - This mode user enters command from inside our code
 */
void non_interactive_mode(void)
{
	char **cmds;
	char *line = NULL;
	int status;

	do {
		line = read_frm_stream();
		cmds = _tokenize(line);
		status = process_handler(cmds);
	free(line);
	line = NULL;
	free(cmds);
	} while (status == 1);
}

