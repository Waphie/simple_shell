#include "main.h"

/**
 * parse_cmd - parses a line and turns it into tokens.
 * @line: line inputed by user to be parse.
 *
 * Return: The array pointers to (tokens),
 * or (NULL) if fails.
 */
char **parse_cmd(char *line)
{
	size_t token_count = 0, tokens_size = INIT_SIZE;
	char **tokens = NULL;
	char *token = strtok(line, DELIMITERS);
	char **temp;

	if (tokens == NULL)
	{
		handle_error("parse_cmd");
		return (NULL);
	}

	while (token != NULL)
	{
		if (token_count >= tokens_size)
		{
			tokens_size *= EXP_FACTOR;
			temp = realloc(tokens, tokens_size * sizeof(char *));

			if (temp == NULL)
			{
				handle_error("parse_cmd");
				free(tokens);
				return (NULL);
			}

			tokens = temp;
		}

		tokens[token_count++] = strdup(token);
		if (tokens[token_count - 1] == NULL)
		{
			handle_error("parse_cmd");
			free_tokens(tokens, token_count);
			return (NULL);
		}
		token = strtok(NULL, DELIMITERS);
	}
	tokens[token_count] = NULL;
	free_tokens(tokens, token_count);
	return (tokens);
}

/**
 * free_tokens - frees the memory allocated to the tokens.
 * @tokens: the token to be freed
 * @token_count: the number of tokens counted
 */
void free_tokens(char **tokens, size_t token_count)
{
	size_t i;

	for (i = 0; i < token_count; i++)
	{
		free(tokens[i]);
	}

	free(tokens);
}
