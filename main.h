#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024

void read_cmd(char *command, size_t size);
void execute_command(char *command);

/*      ERRORS     */
void handle_error(const char *msg);

#endif
