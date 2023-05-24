#include "lists.h"
void execute_me(char **argv)
{
    pid_t child_pid;
    int status;

    /* fork a child process */
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error:");
        return;
    }

    if (child_pid == 0)
    {
        /* this is the child process */

        char *command = argv[0];
        if (execve(command, argv, NULL) == -1)
        {
            perror("Error:");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* this is the parent process */
        do {
            waitpid(child_pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

