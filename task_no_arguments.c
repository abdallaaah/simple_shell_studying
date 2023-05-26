#include "lists.h"
/**
 * main - that loop while exectution the command of the stdinput
 * @argc: the argc is the number of the arguments
 * @argv: arguments it self
 * Return: it is void no return
 */
int main(int argc, char *argv[])
{
char *line = NULL, *dot = NULL;
char *dollar = "#cisfun$ ";
int handle = 0;
size_t len;
ssize_t nread;
char **array;
dot = argv[0];
while (1 && handle == 0 && argc)
{
if (isatty(fileno(stdin)))
write(STDOUT_FILENO, dollar, strlen(dollar));
else
handle = 1;
nread = getline(&line, &len, stdin);
if (line[nread - 1] == '\n')
line[nread - 1] = '\0';
if (nread == -1 && handle == 0)
{
perror("Error in the getline function");
free(line);
exit(EXIT_FAILURE);
}
array = split_to_array(line);
if (array == NULL)
{
free(array);
return (0);
}
if (strcmp(array[0], "env") == 0)
{
print_env();
}
if (strcmp(array[0], "exit") == 0)
{
exit(0);
}
execute_me(array, dot, handle);
}
free(line);
return (0);
}
