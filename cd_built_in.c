#include "shell.h"
/**
 * cd_home - changes dir to home dir, if no arg is passed to cd
 * @args_cpy: command entered by user
 * Return: return an int value
 */
int cd_home(char **args_cpy)
{
	char *home_path;
	char *home_path_cpy;

	home_path = _getenv("HOME");
	if (!home_path)
	{
		perror(args_cpy[1]);
		free(args_cpy);
		return (1);
	}
	home_path_cpy = _strdup(home_path);
	if (!home_path_cpy)
	{
		perror(args_cpy[1]);
		free(args_cpy);
		return (1);
	}
	if (chdir(home_path_cpy) != 0)
	{
		perror(args_cpy[1]);
		free(home_path_cpy);
		free(args_cpy);
		return (1);
	}
	free(home_path_cpy);
	free(args_cpy);
	return (1);
}
/**
 * cd_old_wd - return to old working dir if args[1] == "-"
 * @args_cpy: command entered by user
 * Return: return 1
 */
int cd_old_wd(char **args_cpy)
{
	char *old_wd;
	char curr_wd[BUFFSIZ];

	old_wd = _getenv("OLDPWD");
	if (!old_wd)
	{
		perror(args_cpy[1]);
		free(args_cpy);
		return (1);
	}
	if (getcwd(curr_wd, sizeof(curr_wd)) == NULL)
	{
		perror("getcwd");
		free(args_cpy);
		return (1);
	}
	if (chdir(old_wd) != 0)
	{
		perror(args_cpy[1]);
		free(args_cpy);
		return (1);
	}
	if (setenv("OLDPWD", curr_wd, 1) != 0)
	{
		perror("setenv");
		free(args_cpy);
		return (1);
	}
	free(args_cpy);
	return (1);
}
/**
 * _cd - my custom change directory
 * @args: commands entered by the user
 * Return: returns 1, a signal to loop again
 */
int _cd(char **args)
{
	char **args_copy = NULL;

	if (args[1] == NULL)
	{
		args_copy = _strdup_arr(args);
		if (!args_copy)
		{
			perror("memory allocation failed: args_copy");
			return (1);
		}
		cd_home(args_copy);
	} else if (_strcmp(args[1], "-") != 0)
	{
		if (chdir(args[1]) != 0)
		{
			perror(args[1]);
			return (1);
		}
	} else
	{
		args_copy = _strdup_arr(args);
		if (!args_copy)
		{
			perror("memory allocation failed: args_copy");
			return (1);
		}
		cd_old_wd(args_copy);
	}
	return (1);
}
