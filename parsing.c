#include "shell.h"

/**
 * parse_cmd - Parse the input string into tokens.
 * @line: Input string to be parsed into tokens.
 *
 * Description: Tokenizes the input string based on space &
 * newline delimiters creating an array of tokens (strings)
 *
 * Return: An array of strings (tokens) created from the input string.
 * The last element in the array is (NULL).
 */
char **parse_cmd(char *line)
{
	char **tokens = NULL;
	size_t num_tokens = 0;

	char *token = strtok(line, " \n");

	while (token != NULL)
	{
		num_tokens++;
		tokens = realloc(tokens, sizeof(char *) * num_tokens);
		tokens[num_tokens - 1] = token;
		token = strtok(NULL, " \n");
	}

	tokens = realloc(tokens, sizeof(char *) * (num_tokens + 1));
	tokens[num_tokens] = NULL;

	return (tokens);
}
