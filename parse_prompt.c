#include "shell.h"

/**
 * parse_arguments - Parse the command line into arguments
 * @buffer: The input command line string
 * @args: An array to store the arguments
 *
 * Return: The number of arguments
 */
int parse_arguments(char *buffer, char *args[])
{
    int count = 0;
    char *token;

    token = strtok(buffer, " \t\n\r");

    while (token != NULL && count < MAX_ARGS - 1)
    {
        args[count] = token;
        token = strtok(NULL, " \t\n\r");
        count++;
    }

    args[count] = NULL;
    return count;
}