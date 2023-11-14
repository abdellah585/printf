#include "main.h"

void print_short(va_list args, pfn_t pfn, function_t functions[],
				 int fn_size, int *printed);
void print_long(va_list args, pfn_t pfn, function_t functions[],
				int fn_size, int *printed);

/**
 * get_length - Get the length modifiers from a format string.
 * @format: The format string.
 * @flags: Pointer to a flags_t struct containing any lengths found.
 * @current_index: Pointer to the current index in the format string.
 */
void get_length(const char *format, flags_t *flags, int *current_index)
{
	if (format[*current_index] == 'l')
	{
		flags->l = 1;
		(*current_index)++;
	}
	else if (format[*current_index] == 'h')
	{
		flags->h = 1;
		(*current_index)++;
	}
}

/**
 * process_length - Process's length modifiers for printing.
 * @flags: pointer to a flags_t struct containing the length modifier found.
 * @args: va_list of arguments.
 * @pfn: The func pointer to the func to be used for printing.
 * @printed: A pointer to the count of printed characters.
 */
void process_length(flags_t *flags, va_list args, pfn_t pfn, int *printed)
{
	int fn_size;

	function_t functions[] = {
		{16, print_hex},
		{16, print_HEX},
		{16, print_addrs},
		{8, print_octal},
		{2, print_binary},
		{10, print_unsigned_integer}};

	fn_size = sizeof(functions) / sizeof(functions[0]);

	if (flags->h)
		print_short(args, pfn, functions, fn_size, printed);
	else if (flags->l)
		print_long(args, pfn, functions, fn_size, printed);
}

/**
 * print_short - Prints a short value in the specified base.
 * @args: The va_list containing the value to be printed.
 * @pfn: The function pointer to the function to be used for printing.
 * @functions: An array contain bases value for printing functions.
 * @fn_size: The size of the functions array.
 * @printed: A pointer to the count of printed characters.
 */
void print_short(va_list args, pfn_t pfn, function_t functions[],
				 int fn_size, int *printed)
{
	int i = 0;
	short h_num;
	unsigned short h_unum;
	char buffer[50];

	if (pfn == print_integer)
	{
		h_num = va_arg(args, int);
		_itoa(h_num, buffer);
		*printed += _puts(buffer);
	}
	else
	{
		for (; i < fn_size; i++)
			if (pfn == functions[i].pfn)
			{
				h_unum = va_arg(args, unsigned int);
				*printed += to_base_n(h_unum, functions[i].base, buffer);
				break;
			}
	}
}

/**
 * print_long - Prints a long value in the specified base.
 * @args: The va_list containing the value to be printed.
 * @pfn: The function pointer to the function to be used for printing.
 * @functions: An array contain bases value for printing functions.
 * @fn_size: The size of the functions array.
 * @printed: A pointer to the count of printed characters.
 */
void print_long(va_list args, pfn_t pfn, function_t functions[],
				int fn_size, int *printed)
{
	int i = 0;
	long l_num;
	unsigned long l_unum;
	char buffer[50];

	if (pfn == print_integer)
	{
		l_num = va_arg(args, long);
		_itoa(l_num, buffer);
		*printed += _puts(buffer);
	}
	else
	{
		for (; i < fn_size; i++)
			if (pfn == functions[i].pfn)
			{
				l_unum = va_arg(args, unsigned long);
				*printed += to_base_n(l_unum, functions[i].base, buffer);
				break;
			}
	}
}

