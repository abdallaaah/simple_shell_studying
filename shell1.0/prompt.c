#include "lists.h"
/**
 * main - the main funvtion which will control every tins
 * Return: void
 */

char *read_command(void);
char **split_to_array(char *line);
int execute_me(char **arguments);

int main(void)
{
/* To call the prompt */
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

}while(i);

/* env - prints the current environment */
int argc;
char **argv, **envp;
for (char **env = envp; *env != 0; env++)
{
char *thisEnv = *env;
printf("%s\n", thisEnv);
return 0;
}
}

char *read_command(void)
{
char *cmd = NULL;
size_t len = 0;
getline(&cmd, &len, stdin);
return cmd;
}
