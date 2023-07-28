#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

void display_prompt(void);
int parse_arguments(char *buffer, char *args[]);
char *find_command(char *command);
void my_exit(void);
void my_env(void);
int _putchar(char c);
void _execve(char command[]);

#endif /* SHELL_H */