#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * execute_commands - execute the commands entered by user
 * @cmds: commands entered by user broken down into tokens
 * Return: always (1), enables loop
 */
int execute_commands(char **cmds)
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
		free(cmds);
		perror("Forking failed");
	}
	if (pid == 0)
	{
		if (execve(cmds[0], cmds, NULL) == -1)
			perror("Invalid commands");
		free(cmds);
		exit(EXIT_FAILURE);
	}
	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return (1);
}
