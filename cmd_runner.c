#include "shell.h"
/**
 * cmd_runner - execute the commands entered by user
 * @cmds: commands entered by user broken down into tokens
 * Return: always (1), enables loop
 */
int cmd_runner(char **cmds)
{
	pid_t pid;
	char *abs_path;
	int status;

	abs_path = get_path(cmds);
	if (!abs_path)
	{
		perror("Command does not exist");
		free(abs_path);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		free(abs_path);
		free(cmds);
		perror("Forking failed");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(abs_path, cmds, environ) == -1)
		{
			perror("Invalid commands");
			free(abs_path);
			free(cmds);
			exit(EXIT_FAILURE);
		}
	}
	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	free(abs_path);
	return (1);
}
