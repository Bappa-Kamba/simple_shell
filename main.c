#include "shell.h"

/**
 * main - Simple UNIX command line interpreter
 *
 * Return: Always 0 on success
 */
int main(void)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	char *args[MAX_ARGS];
	char *full_path = NULL;
	size_t length;

	while (1)
	{
		display_prompt();

		if (getline(&buffer, &buffer_size, stdin) == -1)
		{
			_putchar("\n"); /* To handle "end of file" condition (Ctrl+D) */
			break;
		}

		length = _strlen(buffer);
		if (length > 0 && buffer[length - 1] == '\n')
		{
			buffer[length - 1] = '\0';
		}

		if (parse_and_execute(buffer, args, &full_path) == 1)
		{
			continue;
		}
	}

	/* Cleanup */
	if (buffer != NULL)
		free(buffer);

	if (full_path != NULL)
		free(full_path);

	return (0);
}

