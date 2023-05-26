#include "lists.h"
/**
 * execute_me - execute the commands
 * @argv: the tokinezed string hold the command from std input
 * Return: void and dont return any thing
 */
void execute_me(char **argv, char *dot)
{
pid_t pid;
int status;
char *arge[2];
arge[0] = argv[0];
arge[1] = NULL;
pid = fork();
/*while (argv)
{
count++;
}*/
if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(arge[0], arge, environ) == -1)
{
perror(dot);
exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
}
