#include "shell.h"

/**
 * builtin_exit - Exit the shell
 */
void builtin_exit(void)
{
    /* No variable declarations, as there are no variables used */
    _exit(EXIT_SUCCESS);
}
