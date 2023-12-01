#include "main.h"

/**
 * execute_command - execute inputted command.
 * @command: is the command to execute
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		handle_error("fork");
	}

	if (pid == 0)
	{
		if (execlp(command, command, (char *) 0) == -1)
		{
			handle_error("execlp");
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			handle_error("waitpid");
		}
	}
}
