#include "shell.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0 on success
 */
int main(void)
{
    /* Variable declarations at the top */
    char *buffer = NULL;
    size_t buffer_size = 0;
    char *args[MAX_ARGS];
    char *full_path = NULL;
    int status;

    /* Rest of the code follows */
    while (1)
    {
        display_prompt();

        if (getline(&buffer, &buffer_size, stdin) == -1)
        {
            printf("\n"); /* To handle "end of file" condition (Ctrl+D) */
            break;
        }

        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }

        int arg_count = parse_arguments(buffer, args);

        if (arg_count == 0)
        {
            continue;
        }

        if (strcmp(args[0], "exit") == 0)
        {
            builtin_exit();
        }
        else if (strcmp(args[0], "env") == 0)
        {
            builtin_env();
        }
        else
        {
            if (full_path != NULL)
            {
                free(full_path);
            }
            full_path = find_command(args[0]);
            if (full_path == NULL)
            {
                printf("Command not found: %s\n", args[0]);
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
                if (execve(full_path, args, NULL) == -1)
                {
                    perror("Error executing command");
                    free(full_path);
                    _exit(EXIT_FAILURE);
                }

                _exit(EXIT_SUCCESS);
            }
            else
            {
                waitpid(pid, &status, 0);

                if (WIFEXITED(status))
                {
                    int exit_status = WEXITSTATUS(status);
                    if (exit_status != 0)
                    {
                        printf("Command returned non-zero exit status: %d\n", exit_status);
                    }
                }
                else
                {
                    printf("Command did not terminate normally\n");
                }
            }
        }
    }

    /* Cleanup */
    if (buffer != NULL)
    {
        free(buffer);
    }

    if (full_path != NULL)
    {
        free(full_path);
    }

    return (0);
}
