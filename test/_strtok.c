#include "shell.h"

char **_strtok(char *command) {
    int max_tokens = 10; // You can adjust this based on your requirements
    char **tokens = malloc(sizeof(char *) * (max_tokens + 1));
    int i = 0;

    char *str = malloc(strlen(command) + 1);
    strcpy(str, command);

    char *token = strtok(str, " ");
    while (token) {
        tokens[i] = malloc(strlen(token) + 1); // Allocate memory for each token
        strcpy(tokens[i], token);
        i++;

        if (i >= max_tokens) {
            max_tokens *= 2; // Double the size if needed
            tokens = realloc(tokens, sizeof(char *) * (max_tokens + 1));
        }

        token = strtok(NULL, " ");
    }

    tokens[i + 1] = NULL; // Null-terminate the array of tokens
    free(str); // Free the temporary buffer

    return tokens;
}

