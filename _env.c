#include "shell.h"

/**
 * builtin_env - Print the current environment variables
 */
void builtin_env(void)
{
    /* Variable declarations at the top */
    extern char **environ;
    char **env = environ;

    /* Rest of the code follows */
    while (*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }
}
