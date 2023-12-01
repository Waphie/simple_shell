#include "main.h"

/**
 * main - entry point of the shell program
 *
 * Return: (0) Always
 */
int main(void)
{
	char command[1024];
	size_t size = sizeof(command);

	while (1)
	{
		printf("$ ");
		read_cmd(command, size);

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		if (access(command, X_OK) == -1)
		{
			printf("Command not found or not executable\n");
		}
		else
		{
			execute_command(command);
		}
	}

	return (0);
}
