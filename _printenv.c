#include "shell.h"
/**
 * _env - prints the list of environment variables
 * @cmds: command entered by user
 * Return: returns 1 onSuccess or Failure
 */
int _env(char **cmds)
{
	char **env;
	char *current_env_var;
	int num_of_elem_cmds = 0;

	while (!cmds[num_of_elem_cmds])
		num_of_elem_cmds++;
	if (num_of_elem_cmds > 1)
	{
		perror(cmds[0]);
		return (1);
	}
	for (env = environ; *env != NULL; env++)
	{
		current_env_var = *env;
		while (*current_env_var)
		{
			_putchar(*current_env_var);
			current_env_var++;
		}
		_putchar('\n');
	}
	return (1);
}
