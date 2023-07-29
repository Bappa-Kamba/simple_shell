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
#include <stdarg.h>

#define BUFFER_SIZE 1024
#define MAX_ARGS 64

extern char **environ;
#define ENV environ

void display_prompt(void);
int parse_arguments(char *buffer, char *args[]);
char *find_command(char *command);
void my_exit(void);
void my_env(void);
int _putchar(const char *format, ...);
void _execve(char command[]);
int parse_and_execute(char *buffer, char *args[], char **full_path);
int execute_command(char *command, char *args[]);
char *__strdup(const char *str);
char *_strcpy(char *dest, const char *src);
size_t _strlen(const char *str);
int __strcmp(const char *s1, const char *s2);

#endif /* SHELL_H */
