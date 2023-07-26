#include "shell.h"
/**
 * sigint_handler - handles the signal sent by CTRL + C
 * @signum: signal number
 * @info: pointer that contains additional info about signal number
 * @user_data: can be used to pass flag or data needed from calling fxn
 */
void sigint_handler(int signum, siginfo_t *info, void *user_data)
{
	char **line_ptr = (char **)user_data;
	char *line = *line_ptr;
	(void)signum;
	(void)info;
	/* signals the loop to stop */
	printf("Signal encountered");
	printf("Signal encountered again");
	free(line);
	signal(SIGINT, SIG_DFL);
	kill(getpid(), SIGINT);
}
