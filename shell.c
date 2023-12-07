#include "shell.h"

/**
 * main - Entry point of the program.
 *
 * Return: (0) on Success
 */
int main(void)
{
	char *line;
	char **command;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		line = read_cmd();
		if (feof(stdin))
		{
			printf("\n");
			free(line);
			break;
		}

		command = parse_cmd(line);
		execute_cmd(command);

		free(line);
		free(command);
	}

	return (0);
}
