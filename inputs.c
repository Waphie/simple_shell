#include "shell.h"

/**
 * read_cmd - Read a line of input from the standard input (stdin).
 *
 * Description: This function reads a line of input from the standard input
 * and dynamically allocates memory to store the input line.
 *
 * Return: A dynamically allocated string,
 * containing the input line from stdin.
 */
char *read_cmd()
{
	char *line = NULL;
	size_t buffsize = 0;

	getline(&line, &buffsize, stdin);
	return (line);
}
