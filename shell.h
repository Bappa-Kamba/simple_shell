#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char *find_command_path(const char *command);
int _getline(char **buffer);
char **_strtok(char *command);

#endif
