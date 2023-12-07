#include "shell.h"

/**
 * execute_cmd - Execute the given command.
 * @command: An array of strings containing the command and its arguments.
 *
 * Description: This function forks a new process,
 * to execute the provided command and waits for its completion.
 */
void execute_cmd(char **command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execvp(command[0], command) == -1)
		{
			perror("Command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Waitpid failed");
			exit(EXIT_FAILURE);
		}
	}
}
