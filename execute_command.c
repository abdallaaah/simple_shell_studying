#include "lists.h"
/**
 * execute_me - execute the commands
 * @argv: the tokinezed string hold the command from std input
 * @dot: carry the name of the bash
 * @handle: flag to know where is the input
 * Return: void
 */
void execute_me(char **argv, char *dot, int handle, int count)
{
pid_t pid;
int status;
/*char *arge[2];
arge[0] = argv[0];
arge[1] = NULL;*/
pid = fork();
count = 5;
if (pid == -1)
{
perror("fork error");
/*exit(EXIT_FAILURE);*/
}
else if (pid == 0 && count && handle == 0)
{
if (execve(argv[0], argv, environ) == -1 /*&& handle == 0*/)
{
perror(dot);
/*exit(EXIT_FAILURE);*/
}
}
else if (pid == 0 && count && handle == 1)
{
if (execve(argv[0], argv, environ) == -1 /*&& handle == 0*/)
{
perror(dot);
/*exit(EXIT_FAILURE);*/
}
}
else
{
waitpid(pid, &status, 0);
}
/*if (handle == 1)
{
printf("the argv is: %s\n",argv[0]);
execve(argv[0], argv, environ);
}*/
}
