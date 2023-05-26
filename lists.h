#ifndef LISTS_H
#define LISTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char **environ;
char **split_to_array(char *line);
char **commands_to(char *str);
char **spliting(char *line);
void execute_me(char **argv, char *dot, int handle);
void print_env(void);
#endif
