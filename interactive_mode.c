#include "shell.h"
/**
 * interactive_mode - This mode user enters command from inside our code
 */
void interactive_mode(void)
{
	char **cmds;
	char *line = NULL;
	int status;
	struct sigaction sig_act;

	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_sigaction = sigint_handler;
	sigemptyset(&sig_act.sa_mask);
	if (sigaction(SIGINT, &sig_act, (void *)&line) == -1)
	{
		perror("Sigaction failed");
		free(line);
		exit(EXIT_FAILURE);
	}
	do {
		write(STDOUT_FILENO, "$ ", 2);
		line = read_input();
		cmds = _tokenize(line);
		status = process_handler(cmds);
	free(line);
	line = NULL;
	free(cmds);
	} while (status == 1);
}

