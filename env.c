#include "shell.h"

/**
 * my_env - Print the current environment variables
 */
void my_env(void)
{
	char **env = ENV;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
