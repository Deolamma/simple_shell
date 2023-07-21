#include "shell.h"
/**
 * _cd - my custom change directory
 * @args: commands entered by the user
 * Return: returns 1, a signal to loop again
 */
int _cd(char **args)
{
	char *home_path;

	if (args[1] == NULL)
	{
		home_path = getenv("HOME");
		if (!home_path)
		{
			perror("HOME NOT SET");
			free(home_path);
			return (1);
		}
		if (chdir(home_path) != 0)
		{
			perror("HOME IS NOT A DIRECTORY");
			free(home_path);
			return (1);
		}
		free(args);
		return (1);
	}
	if (chdir(args[1]) != 0)
	{
		perror("DIRECTORY DOESN'T EXIST");
		free(args);
		return (1);
	}
	free(args);
	return (1);
}
