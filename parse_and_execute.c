#include "shell.h"

/**
 * execute_absolute_path - Execute the command if it's an absolute path
 * @command: The full path of the command to execute
 * @args: The arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_absolute_path(char *command, char *args[])
{
	if (access(command, X_OK) == 0)
	{
		if (execute_command(command, args) == -1)
		{
			return (-1);
		}
	}
	else
	{
		_putchar("Command not found: %s\n", command);
		return (-1);
	}

	return (0);
}

/**
 * parse_and_execute - Parse and execute the command
 * @buffer: The input command line string
 * @args: An array to store the arguments
 * @full_path: Pointer to the full path of the command
 *
 * Return: 1 if the shell should continue, 0 otherwise
 */
int parse_and_execute(char *buffer, char *args[], char **full_path)
{
	int arg_count = parse_arguments(buffer, args);

	if (arg_count == 0)
		return (1);

	if (__strcmp(args[0], "exit") == 0)
	{
		my_exit();
		return (0);
	}
	else if (__strcmp(args[0], "env") == 0)
	{
		my_env();
		return (1);
	}

	if (args[0][0] == '/')
		return (execute_absolute_path(args[0], args));

	if (*full_path != NULL)
		free(*full_path);
	*full_path = find_command(args[0]);

	if (*full_path == NULL)
	{
		_putchar("Command not found: %s\n", args[0]);
		return (1);
	}

	if (execute_command(*full_path, args) == -1)
	{
		return (1);
	}

	return (1);
}

