#include "shell.h"
#include <ctype.h>
/**
 * my_exit - implements the exit builtin
 * @cmds: commands entered by user
 * Return: returns an int value
 */
int my_exit(char **cmds)
{
	int num_args = 0;
	int i, exit_stat;
	char *exit_stat_str;

	while (cmds[num_args])
		num_args++;
	if (num_args > 2)
	{
		perror("Too many arguments");
		return (1);
	}
	if (num_args == 1)
	{
		free(cmds);
		exit(EXIT_SUCCESS);
	} else if (num_args == 2)
	{
		exit_stat_str = cmds[1];
		for (i = 0; exit_stat_str[i]; i++)
		{
			if (!isdigit(exit_stat_str[i]))
			{
				perror("Not a valid number");
				return (1);
			}
		}
		exit_stat = atoi(exit_stat_str);
		free(cmds);
		fflush(stdin);
		exit(exit_stat);
	}
	return (1);
}

