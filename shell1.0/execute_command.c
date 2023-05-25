#include "lists.h"
/**
 * execute_me - execute the commands
 * @argv: the tokinezed string hold the command from std input
 * Return: void and dont return any thing
 */

int execute_me(char **arguments)
{
/* printf("%*c\n", arguments); */
int pid, waitPid, i;

pid = fork();

/* child process */
if(pid == 0)
{
if (execvp(arguments[0], arguments) == -1)
perror("Error with EXECVP\n");
}
else if (pid < 0)
perror("Error PID < 0\n");
/* parent process */
else
{
do
{
waitPid = waitpid(pid, &i, WUNTRACED);
}while(!WIFEXITED(i) && !WIFSIGNALED(i));
}
return 1;
}
