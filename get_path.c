#include "shell.h"
/**
 * get_path - finds the value of the path and tokenizes the value
 * @args: an array of commands entered by the user
 * Return: returns the absolute path of a command or NULL
 */
char *get_path(char **args)
{
	char *path_val;
	char *path_val_copy;
	char *path_val_tok;
	char cmd_path[BUFFSIZ];

	path_val = _getenv("PATH");
	if (!path_val)
		return (NULL);
	/* This copy was created because of the reentrant nature of getenv */
	/* on successive calss */
	path_val_copy = _strdup(path_val);
	if (path_val_copy)
	{
		path_val_tok = strtok(path_val_copy, ":");
		while (path_val_tok)
		{
			_strcpy(cmd_path, path_val_tok);
			_strcat(cmd_path, "/");
			_strcat(cmd_path, args[0]);
			if (access(cmd_path, X_OK) == 0)
			{
				free(path_val_copy);
				return (_strdup(cmd_path));
			}
			path_val_tok = strtok(NULL, ":");
		}
	}
	return (NULL);
}

