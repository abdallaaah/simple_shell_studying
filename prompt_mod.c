#include "lists_mod.h"
/**
 * main - the main funvtion which will control every tins
 * Return: void
 */

char *read_command(void);
char **split_to_array(char *line);
int execute_me(char **arguments);

int main(void)
{
char *cmd = NULL;
char **arguments;
int i;

do
{
printf("Abdallah/Ibrahim/:)$ ");
cmd = read_command();
arguments = split_to_array(cmd);
i = execute_me(arguments);

free(arguments);
free(cmd);

}
while(i);
return (0);
}

char *read_command(void)
{
char *cmd = NULL;
size_t len = 0;
getline(&cmd, &len, stdin);
return cmd;
}
