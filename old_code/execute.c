#include "main.h"

/**
 * execute_cmd - executes inputted command.
 * @args: An array of pointers to command and arguments.
 *
 * Return: void(nothing).
 */
int execute_cmd(char **args)
{
	pid_t pid = fork();
	int status;

	if (pid == -1)
	{
		handle_error("fork");
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			handle_error("execute_cmd");
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			handle_error("waitpid");
		}
	}

	return (0);
}
