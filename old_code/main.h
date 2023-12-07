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
#include <ctype.h>

#define MAX_LINE_LEN 4096
#define MAX_CMD_LENGTH 1024
#define DELIMITERS " \t\r\n\a"
#define EXP_FACTOR 4
#define INIT_SIZE 100
#define BUFFSIZE 1024

extern char **environ;

int read_cmd(char *command, size_t size);
int execute_cmd(char **args);
void fetch_env(char *name);

/*      ERRORS     */
void handle_error(const char *msg);

/*      EXIT       */
void exit_cmd(char **args);

/*      parse      */
char **parse_cmd(char *line);
void free_tokens(char **tokens, size_t token_count);

/*      getline    */
/*ssize_t fetch_line(char **lineptr, size_t *n, FILE *stream);*/

#endif
