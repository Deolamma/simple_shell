#include "shell.h"
/**
 * abs_path_cmd_runner - execute the commands entered by user
 * @cmds: commands entered by user broken down into tokens
 * Return: always (1), enables loop
 */
int abs_path_cmd_runner(char **cmds)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror(cmds[0]);
		free(cmds);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(cmds[0], cmds, NULL) == -1)
		{
			perror(cmds[0]);
			error_handler(cmds);
			exit(EXIT_SUCCESS);
		}
	}
	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	return (1);
}
