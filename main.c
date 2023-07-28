#include "shell.h"

int main(void)
{
    char *command;

    while (1)
    {
        printf("$ ");
        command = read_line();
        execute_command(command);
        free(command);
    }

    return 0;
}