#include "shell.h"

char *find_command_path(const char *command) {
	if(access(command, F_OK) == 0)
		return command;

	// Retrieve the PATH environment variable
    char *path_env = getenv("PATH");
    if (path_env == NULL) {
        fprintf(stderr, "Error: PATH environment variable not set.\n");
        return NULL;
    }

    // Tokenize the PATH variable
    char *path_copy = strdup(path_env);
    char *token = strtok(path_copy, ":");

    // Loop through each path in the PATH variable
    while (token != NULL) {
        char *cmd_path = (char *)malloc(strlen(token) + strlen(command) + 2); // +2 for '/' and null terminator
        sprintf(cmd_path, "%s/%s", token, command);

        // Check if the constructed path exists and is executable
        if (access(cmd_path, X_OK) == 0) {
            free(path_copy);
            return cmd_path; // Return the constructed command path
        }

        free(cmd_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);

    // Command not found in any of the PATH directories
    return NULL;
}

int main(void) {
    int status = 0;
    pid_t pid = getpid();
    printf("%u\n", pid);

    do {
        size_t n = 10;
        char *buf = NULL;

        size_t result = _getline(&buf);
        if (result == -1)
            break;
		if (strcmp(buf,"exit") == 0)
		{
			printf("Exiting...\n");
			break;
		}

        char **tokens = _strtok(buf);

		char *cmd_path = find_command_path(tokens[0]);

		int child = -1;
		if (cmd_path)
			child = fork();
        if (child == 0) {
            // Execute the command using execve
			extern char **environ;
            int exeerr = execve(cmd_path, tokens, environ);

            if (exeerr == -1)
                perror("Error");

            free(cmd_path); // Free the memory allocated for cmd_path

            // Free the memory allocated for tokens
            int i = 0;
            while (tokens[i] != NULL) {
                free(tokens[i]);
                i++;
            }
            free(tokens);

            exit(EXIT_SUCCESS); // Terminate the child process after execution
        } else {
            wait(NULL);
            status = 0;
        }

        // Free the memory allocated for buf
        free(buf);
    } while (status == 0);

    return (0);
}
