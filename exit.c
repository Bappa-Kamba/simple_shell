#include "shell.h"

/**
 * my_exit - Exit the shell
 */
void my_exit(void)
{
	printf("Exiting...");
	_exit(EXIT_SUCCESS);
}
