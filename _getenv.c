#include "shell.h"
/**
 * _getenv - gets the values of the env. variable specified e.g. PATH
 * @env_name: name of the environment variable we want to work with e.g. PATH
 * Return: returns a pointer to the first element of the value
 */
char *_getenv(char *env_name)
{
	char **env;
	int len_env_name;

	len_env_name = _strlen(env_name);
	for (env = environ; *env != NULL; env++)
	{
		if ((_strncmp(env_name, *env, len_env_name) == 0) &&
				((*env)[len_env_name]) == '=')
			return (&((*env)[len_env_name + 1]));
	}
	return (NULL);
}

