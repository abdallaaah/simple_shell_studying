#include "lists.h"
/**
 * split_to_array - it used for spliting the line from main to tokenz in array
 * @line: the line by user from the standard input
 * Return: tokeinzed array of strinput
 */
char **split_to_array(char *line)
{
char *token = NULL, *token_2 = NULL;
char *line_2 = NULL;
char **sttr = NULL;
int i = 0;
int count = 1;
line_2 = malloc(strlen(line));
if (line_2 == NULL)
{
perror("(Error in malloc and memory size)");
return (NULL);
}
line_2 = strcpy(line_2, line);
token = strtok(line, " ");
while (token != NULL)
{
count++;
token = strtok(NULL, " ");
};
sttr = malloc(sizeof(char *) * count);
token_2 = strtok(line_2, " ");
for (i = 0; token_2 != NULL; i++)
{
sttr[i] = malloc(sizeof(char) * (strlen(token_2)));
strcpy(sttr[i], token_2);
token_2 = strtok(NULL, " ");
}
sttr[i] = NULL;
free(line_2);
return (sttr);
}
