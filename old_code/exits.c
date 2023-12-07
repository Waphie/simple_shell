#include "main.h"

/**
 * exit_cmd - is a function that handlesthe exit command
 * @args: An array of pointers to command and arguments.
 */
void exit_cmd(char **args)
{
	int status = 0;
	int i = 1;

	for (i = 1; args[i] != NULL; i++)
	{
		if (i > 1)
		{
			handle_error("exit: too many arguments\n");
			return;
		}

		status = atoi(args[i]);
		if (status < 0)
		{
			handle_error("exit: wrong number: ");
			handle_error(args[i]);
			handle_error("\n");
			return;
		}
	}

	exit(status);
}
