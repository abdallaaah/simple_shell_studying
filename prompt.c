#include "lists.h"
/**
 * main - the main funvtion which will control every tins
 * Return: void
 */
int main(void)
{
char *line = NULL;
char *dollar = "$ ";
char **str;
size_t len;
ssize_t nread;
int flag = 0;
while (1 && flag == 0)
{
if (isatty(STDIN_FILENO == 0))
{

}
write(STDOUT_FILENO, dollar, 2);
nread = getline(&line, &len, stdin);
if (line[nread - 1] == '\n')
{
line[nread - 1] = '\0';
}
if (nread == -1)
{
perror("(Error in getline)");
free(line);
exit(EXIT_FAILURE);
}
/*str = split_to_array(line);*/
str = split_to_array(line);
execute_me(str);
}
free(line);
return (0);
}
