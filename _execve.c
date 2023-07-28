#include "shell.h"

/**
 * _execve - executes command
 */
void _execve(char command[], char *args_list)
{
    char *full_path = NULL;

    if (full_path != NULL)
    {
        free(full_path);
    }

    full_path = find_command(args[0]);

    if (full_path == NULL)
    {
        printf("Command not found: %s\n", command[0]);
        continue;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        free(full_path);
        _exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execve(full_path, args_list, NULL) == -1)
        {
            perror("Error executing command");
            free(full_path);
            _exit(EXIT_FAILURE);
        }
        _exit(EXIT_SUCCESS);
    }
}