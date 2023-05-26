#include "lists.h"
int main(int argc, char *argv[])
{
char *line = NULL, *dot = NULL;
char *dollar = "#cisfun$ ";
int handle = 0;
char *token;
int i = 0;
size_t len = 0;
ssize_t nread = 0;
char **array = NULL;
int max_elements = 20; 
int num_elements = 0; 
dot = argv[0];
line = (char *) malloc(sizeof(char) * len);

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

  
    array = (char **) malloc(sizeof(char *) * max_elements);
     token = strtok(line, " ");
    while (token != NULL) {
        if (num_elements >= max_elements) {
            max_elements *= 2;
            array = (char **) realloc(array, sizeof(char *) * max_elements);
            if (!array) {
                perror("Error allocating memory");
                exit(EXIT_FAILURE);
            }
        }
        array[num_elements] = (char *) malloc(strlen(token) + 1);
        if (!array[num_elements]) {
            perror("Error allocating memory");
            exit(EXIT_FAILURE);
        }
        strcpy(array[num_elements], token);

        num_elements++;
        token = strtok(NULL, " ");
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
    for (i = 0; i < num_elements; i++) {
        free(array[i]);
    }
   
    free(array);
    free(line); 
    line = NULL;

}

free(line);
return (0);
}
