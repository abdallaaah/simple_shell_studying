#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

extern char** environ;
/**
 * main - the main function that loop while exectution the command of the stdinput
 * Return: no return it is void
 */
int main(void)
{
char *args[2];
char *line = NULL;
char *dollar = "$ ";
int status;
size_t len;
ssize_t nread;
/*int pipe_flag = 0;*/
pid_t pid;
int handle = 0;
while (1 && /*pipe_flag != 1*/ handle == 0)
{
if (isatty(fileno(stdin)))
{
write(STDOUT_FILENO, dollar, strlen(dollar));
}
else
{
handle = 1;
}
nread = getline(&line, &len, stdin);
/*if ( pipe_flag == 1 || nread > 0)
{
write(STDOUT_FILENO, dollar, strlen(dollar));
}*/
if (line[nread - 1] == '\n'){
line[nread - 1] = '\0';
}
if (nread == -1 && handle == 0)
{
perror("Error in the getline function");
free(line);
exit(EXIT_FAILURE);
}
args[0] = line;
args[1] = NULL;
pid = fork();
if (pid == -1)
{
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0){
if (execve(args[0], args, environ) == -1){
perror("execv");
exit(EXIT_FAILURE);
}
}
else{
waitpid(pid, &status, 0);
}
/*if(pipe_flag == 1)
{
break;
}*/
}
return 0;
}
