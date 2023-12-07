#include "main.h"

/**
 * fetch_env - handles the PATH in the shell
 * @name: is where the acutally PATH is.
 */
void fetch_env(char *name)
{
	if (name == NULL)
	{
		char **env = NULL;

		for (env = environ; *env != NULL; env++)
		{
			printf("%s\n", *env);
		}
	}
	else
	{
		char *env_value = getenv(name);

		if (env_value != NULL)
		{
			printf("%s\n", env_value);
		}
		else
		{
			printf("No such environment variable: %s\n", name);
		}
	}
}
