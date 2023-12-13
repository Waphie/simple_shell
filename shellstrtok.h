#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"
#ifndef SHELLSTRTOK_H
#define SHELLSTRTOK_H
#pragma once

int tokenize(char *line);
int add_node(char *word);

/*
 * Rest of the code
*/

void execute_command(char *command)
{
char *argv[256];
int argc = 0;
char *token = strtok(command, " ");

while (token != NULL && argc < 255)
{
argv[argc++] = token;
token = strtok(NULL, " ");
	i }

argv[argc] = NULL;

	pid = fork();

		if (pid == -1)
{
		perror("fork");
		exit(EXIT_FAILURE);
		}
		if (pid == 0)
{
				if (execvp(argv[0], argv) == -1)
		{
		perror("execvp");
		exit(EXIT_FAILURE);
		}
			}
		else
		{

			int status;

			if (waitpid(pid, &status, 0) == -1)

		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		}
}

int main(void)
{
		pid_t pid;
		char command[1024];
		size_t length;

		while (1)
		{
			write(1, "> ", 2);
			if (read(0, command, sizeof(command) - 1) == 0)
			{
				exit(0);
			}
			length = strlen(command);

				if (command[length - 1] == '\n')
			{

			command[length - 1] = '\0';
			}
			if (strlen(command) == 0)
			{
				continue;
			}
execute_command(command);
}

return (0);
}
