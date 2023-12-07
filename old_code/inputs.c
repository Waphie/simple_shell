#include "main.h"

/**
 * read_cmd - reads user input
 * @command: the command to be read
 * @size: stores user input
 *
 * Return: 0 on succesful
 */
int read_cmd(char *command, size_t size)
{
	size_t len = 0;
	int c;

	while ((c = getchar()) != EOF && c != '\n')
	{
		if (len == size - 1)
		{
			fprintf(stderr,
				"Input exceeds max length. Ignore the rest of input.\n");
		}
		else if ((c = getchar()) != '\n' && c != EOF)
		{
			/*no code implementation yet*/
		}
		else
		{
			command[len++] = c;
		}
	}

	command[len] = '\0';
	getchar();
	return (0);
}
