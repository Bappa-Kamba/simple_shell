#include "shell.h"

/**
 * find_command - Search for the command in PATH or absolute path
 * @command: The command to search for
 *
 * Return: The full path of the command if found, otherwise NULL
 */
char *find_command(char *command)
{
	struct stat st;
	char *path = getenv("PATH");
	char *token, *path_copy;
	char *full_path = (char *)malloc(BUFFER_SIZE);

	if (path == NULL || full_path == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("Memory allocation error");
		free(full_path);
		return (NULL);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(full_path, BUFFER_SIZE, "%s/%s", token, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	free(full_path);
	return (NULL);
}
