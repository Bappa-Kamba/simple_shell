#include "shell.h"

/**
 * _putchar - Writes formatted output to stdout
 * @format: The format string
 * @...: The arguments to format
 *
 * Return: On success, the number of characters written.
 * On error, -1 is returned.
 */
int _putchar(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int i = 0, j = 0;

	if (format == NULL)
		return -1;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				buffer[j++] = va_arg(args, int);
				break;
			case 's':
				{
					const char *str = va_arg(args, const char *);
					int k = 0;
					while (str[k] != '\0')
						buffer[j++] = str[k++];
				}
				break;
			default:
				buffer[j++] = '%';
				buffer[j++] = format[i];
				break;
			}
		}
		else
		{
			buffer[j++] = format[i];
		}
		i++;
	}

	va_end(args);

	return write(1, buffer, j);
}

