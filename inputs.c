#include "main.h"

/**
 * read_cmd - reads user input
 * @command: the command to be read
 * @size: stores user input
 */
void read_cmd(char *command, size_t size)
{
	size_t len = strlen(command);
	int c;

	if (fgets(command, size, stdin) == NULL)
	{
		handle_error("fgets");
	}

	if (len == size - 1 && command[len - 1] != '\n')
	{
		fprintf(stderr,
				"Input exceeds maximum length. Ignore the rest of the input.\n");

		while ((c = getchar()) != '\n' && c != EOF)

		command[size - 1] = '\0';
	}
	else if (command[len - 1] == '\n')
	{
		command[len - 1] = '\0';
	}
}
