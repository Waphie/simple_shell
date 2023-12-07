#include "main.h"

/**
 * main - the entry point of the program
 *
 * Return: (0) on success.
 */
int main(void)
{
	char *line;
	char **args;
	int status;
	size_t size = INIT_SIZE;
	char *command = malloc(size);

	if (command == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	do {
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}

		line = command;
		if (read_cmd(command, size) == -1)
		{
			free(command);
			break;
		}

		args = parse_cmd(line);
		if (strcmp(args[0], "exit") == 0)
		{
			exit_cmd(args);
			free(line);
			free(args);
			continue;
		}
		else if (strcmp(args[0], "env") == 0)
		{
			fetch_env(args[1]);
			free(line);
			free(args);
			continue;
		}

		execute_cmd(args);
		free(line);
		free(args);
		status = 0;
	} while (status);
	return (0);
}
