#include "shell.h"
int (*built_in_func[])(char **) = {
	&_cd,
	&_env
};
/**
 * process_handler - determines if the command is a builtin or abs. path
 *@args: commands entered by user
 *Return: returns appropriate process to be executed
 */
int process_handler(char **args)
{
	int i, built_in_num;
	char *built_in[] = {"cd", "env"};

	built_in_num = sizeof(built_in) / sizeof(char *);
	/* User pressed the enter key without typing a command */
	if (args[0] == NULL)
		return (1);
	for (i = 0; i < built_in_num; i++)
	{
		if ((_strcmp(args[0], built_in[i])) == 0)
			return ((*built_in_func[i])(args));
	}
	if (args[0][0] == '/')
	{
		return (abs_path_cmd_runner(args));
	}
	return (cmd_runner(args));
}

