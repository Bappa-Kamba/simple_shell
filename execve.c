#include "shell.h"

/**
 * execute_command - Execute the command using execve
 * @command: The full path of the command to execute
 * @args: The arguments for the command
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command, char *args[])
{
	pid_t pid;
	int status;
	int exit_status;

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("Error executing command");
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
			{
				_putchar("Command returned non-zero exit status: %d\n", exit_status);
			}
		}
		else
		{
			_putchar("Command did not terminate normally\n");
		}
	}

	return (0);
}
