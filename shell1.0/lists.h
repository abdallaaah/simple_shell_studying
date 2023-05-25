#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char **split_to_array(char* line);
char **commands_to(char* str);
char** spliting(char* line);
char **parse_line(char *line);
int execute_me(char** str);
#endif
