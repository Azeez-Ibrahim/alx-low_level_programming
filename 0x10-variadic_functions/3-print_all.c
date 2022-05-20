#include "variadic_functions.h"
#include <stdio.h>

/**
 * _strlen - Length of string
 * @s: String passed
 *
 * Return: Length of string
 */
int _strlen(const char * const s)
{
	switch  (*s)
	{
	case '\0':
		return (0);
	default:
		break;
	}
	return (1 + _strlen(s + 1));
}

/**
 * print_all - Prints everything
 * @format: List of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int i = 0, len = 0;
	va_list args;
	char *str;

	va_start(args, format);
	while (format != NULL && len == 0)
		len  = _strlen(format) + 1;
	len -= 1;
	while (i < len && format != NULL)
	{
		switch (*(format + i))
		{
		case 'c':
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
			{
				printf("(nil)");
				break;
			}
			printf("%s", str);
		default:
			break;
		}
		if ((i != len - 1) && ((*(format + i) == 'c'
			|| *(format + i) == 'i') || (*(format + i) == 'f'
			|| *(format + i) == 's')))
			printf(", ");
		i++;
	}
	va_end(args);
	putchar('\n');
}
