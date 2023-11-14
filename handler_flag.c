#include "main.h"

/**
 * get_flags - Extracts flags from a format string.
 * @format: The format string.
 * @flags: Pointer to a flags_t struct containing any flags found.
 * @current_index: Pointer to the current index in the format string
 */
void get_flags(const char *format, flags_t *flags, int *current_index)
{
	for (flags->j = *current_index; format[flags->j]; flags->j++)
	{
		if (format[flags->j] == '+')
			flags->plus = 1;
		else if (format[flags->j] == '#')
			flags->hash = 1;
		else if (format[flags->j] == ' ')
		{
			if (format[flags->j + 1] == '%')
				(*current_index)++;
			else
				flags->space = 1;
		}
		else
			break;
	}
	*current_index = flags->j;
}

/**
 * process_flags - process's flags for printing.
 * @flags: pointer to a flags_t struct containing the flags found.
 * @args_flags: va_list of arguments.
 * @conversion_func: pointer to the conversion function.
 * @printed: pointer to the count of printed chars.
 */
void process_flags(flags_t *flags, va_list args_flags,
				 pfn_t conversion_func, int *printed)
{
	int num;
	unsigned long l_unum;

	if (conversion_func == print_integer)
		num = va_arg(args_flags, long);
	else
		l_unum = va_arg(args_flags, long);

	if (flags->plus && flags->space)
		flags->space = 0;
	/* handle flag: (+) and (space) */
	if (flags->plus && num >= 0)
		*printed += _putchar('+');
	else if (flags->space && num >= 0 && conversion_func == print_integer)
		*printed += _putchar(' ');
	/* handle flag: (#) */
	if (flags->hash)
	{
		if (conversion_func == print_octal && l_unum > 0)
			*printed += _putchar('0');
		else if (conversion_func == print_hex && l_unum > 0)
			*printed += _puts("0x");
		else if (conversion_func == print_HEX && l_unum > 0)
			*printed += _puts("0X");
	}
}

