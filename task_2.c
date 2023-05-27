#include "lists.h"

char *read_command(void);

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
size_t len = 0;
ssize_t nread = 0;
int count = 0, i = 0;
char **array = NULL;
dot = argv[0], count = argc;
while (handle == 0)
{
if (isatty(fileno(stdin)))
write(STDOUT_FILENO, dollar, 9);
else
{
handle = 1;
}
nread = getline(&line, &len, stdin);
if (line[nread - 1] == '\n')
line[nread - 1] = '\0';
if (nread == -1)
perror("Error in getline()"), exit(EXIT_FAILURE);
array = split_to_array(line, count, &count);
if (strcmp(array[0], "env") == 0)
print_env();
if (strcmp(array[0], "exit") == 0)
{
for (i = 0; i < count; i++)
free(array[i]);
free(array);
free(line);
exit(0);
}
execute_me(array, dot, handle, count);
for (i = 0; i < count; i++)
free(array[i]);
free(array);
}
free(line);
return (0);
}

