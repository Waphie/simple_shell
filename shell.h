#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFSIZE 1024

void execute_cmd(char **command);
char **parse_cmd(char *line);
char *read_cmd();

#endif
