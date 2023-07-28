#include "shell.h"

int _getline(char **buffer)
{
	size_t size = 0;

	printf("$: ");
	if(getline(buffer, &size, stdin) == -1)
	{
		return (-1);
	}
	else{
		(*buffer)[strcspn(*buffer, "\n")] = '\0'; // Remove newline character
        return (size - 1);
	}
}
