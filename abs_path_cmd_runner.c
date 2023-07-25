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

	if (cmds[0] == NULL)
	{
		/* User pressed enter key */
		return (1);
	}

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
			free(cmds);
			exit(EXIT_FAILURE);
		}
	}
	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return (1);
}
