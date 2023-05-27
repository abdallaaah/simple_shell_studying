#include "lists.h"
/**
 * split_to_array - function to split the line into array
 * @count: count is the total line arg
 * @line: the line from the std
 * @result_count: pointer to the count
 * Return: the array of tokinized
 */
char **split_to_array(char *line, int count, int *result_count)
{
char *token = NULL, *token_2 = NULL,  *line_2 = NULL, *line_copy = NULL;
char **sttr = NULL;
int i = 0;
line_copy = strdup(line);
if (line_copy == NULL)
{
perror("(Error in malloc and memory size)"), return (NULL);
}
token = strtok(line_copy, " ");
while (token != NULL)
{
count++, token = strtok(NULL, " ");
};
sttr = malloc(sizeof(char *) * (count + 1));
if (sttr == NULL)
{
perror("(Error in malloc and memory size)"), free(line_copy), return (NULL);
}
line_2 = strdup(line);
if (line_2 == NULL)
{
perror("(Error in malloc and memory size)"), free(sttr), free(line_copy);
return (NULL);
}
token_2 = strtok(line_2, " ");
for (i = 0; token_2 != NULL; i++)
{
sttr[i] = strdup(token_2);
if (sttr[i] == NULL)
{
perror("(Error in malloc and memory size)"), free(line_2), goto finally;
}
token_2 = strtok(NULL, " ");
}
*result_count = count;
sttr[i] = NULL;
finally:
free(line_2), free(line_copy);
return (sttr);
}

