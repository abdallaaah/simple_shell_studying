#include "lists.h"
/**
 * print_env - print environment
 * Return: void no return
 */
void print_env(void)
{
char **env = environ;
while (*env != NULL)
{
printf("%s\n", *env);
env++;
};
}
