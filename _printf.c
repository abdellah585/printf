#include "main.h"

int is_valid_specifier(const char *format, int *i);

/**
 * _printf - Prints a formatted string to stdout, similar to printf.
 * @format: The format string specifying the output.
 *
 * This function prints a formatted string to the stdout stream. It
 * accepts a format string as its first argument, and additional arguments
 * are used to replace format specifiers in the format string. The function
 *
 * Return: The number of characters printed to the stdout stream.
 */
int _printf(const char *format, ...)
{
	va_list args, flags_args, width_args;
	flags_t flags = {0};
	width_t width = {0};
	int (*conversion_func)(va_list);
	int i = 0, total_printed = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	(va_copy(flags_args, args), va_copy(width_args, args));

	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (!is_valid_specifier(format, &i))
				return (-1);

			/* Extract flags, width, and get conversion function */
			conversion_func = get_conversion(format, &i, args, &flags, &width);

			/* Process flags, width, and length modifiers */
			process_flags(&flags, flags_args, conversion_func, &total_printed);
			process_width(&width, width_args, conversion_func, &total_printed);
			process_length(&flags, args, conversion_func, &total_printed);

			if (flags.h || flags.l)
				continue;

			/* Call the appropriate conversion function or print as is */
			total_printed += conversion_func
				? conversion_func(args)
				: _putchar('%') + _putchar(format[i]);
		}
		else
		{
			total_printed += _putchar(format[i]);
		}
	}

	va_end(args);
	(va_end(flags_args), va_end(width_args));

	return (total_printed);
}

/**
 * is_valid_specifier - Checks if the character following '%'
 * is a valid specifier.
 * @format: The string to be evaluated.
 * @i: Pointer to the index of the character being evaluated.
 * Return: 1 if valid specifier, 0 otherwise.
 */
int is_valid_specifier(const char *format, int *i)
{
	int j;

	/* Check if there is no character after '%' */
	if (format[++(*i)] == '\0')
		return (0);

	j = *i;

	/* Ignore spaces after '%' */
	for (; format[j] == ' '; j++)
	{
		if (format[*i + 1] == '\0')
			return (0);
		else if (format[*i + 1] == ' ')
			(*i)++;
		else
			break;
	}

	/* Ignore extra valid_specifier between '%' and 'specifier' */
	return (1);
}

