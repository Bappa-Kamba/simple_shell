#include "shell.h"

/**
 * builtin_env - Print the current environment variables
 */
void my_env(void)
{
    extern char **environ;
    char **env = environ;

    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
