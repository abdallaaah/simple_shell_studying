#include "lists.h"
/**
 * execute_me - execute the commands
 * @argv: the tokinezed string hold the command from std input
 * Return: void and dont return any thing
 */
void execute_me(char **argv)
{
char *command = NULL;
char *envp[] = {"PATH=/usr/bin", NULL};
command = argv[0];
if (execve(command, argv, NULL) == -1)
{
perror("Error:");
};
}
