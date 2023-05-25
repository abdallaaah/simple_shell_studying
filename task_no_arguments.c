#include "lists.h"
/**
 * main - that loop while exectution the command of the stdinput
 * @argc: the argc is the number of the arguments
 * @argv: arguments it self
 * Return: it is void no return
 */
int main(int argc, char *argv[])
{
char *args[2];
char *line = NULL, *dot = NULL;
char *dollar = "#cisfun$ ";
int status, handle = 0;
size_t len;
ssize_t nread;
pid_t pid;
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
perror("Error in the getline function"), free(line), exit(EXIT_FAILURE);
args[0] = line, args[1] = NULL, pid = fork();
if (pid == -1)
{
perror("fork error"), exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(args[0], args, environ) == -1)
{
perror(dot), exit(EXIT_FAILURE);
}
}
else
{
waitpid(pid, &status, 0);
}
}
free(line);
return (0);
}
