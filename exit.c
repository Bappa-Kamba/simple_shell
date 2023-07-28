#include "shell.h"

/**
 * builtin_exit - Exit the shell
 */
void my_exit(void)
{
    printf("Exiting...");
    _exit(EXIT_SUCCESS);
}
