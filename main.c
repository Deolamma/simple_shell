#include "shell.h"
#include <unistd.h>
/**
 * main - Entry point into the simple_shell project
 * it checks if we are in interactive or non-interactive mode
 * Return: 0 on Success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	}
	non_interactive_mode();
	return (0);
}

