#include "main.h"

/**
 * print_integer - prints integers from a va_list.
 * @list: va_list of integers to be printed.
 * Return: number of characters printed.
 */
int print_integer(va_list list)
{
	int num = va_arg(list, int);
	char buffer[50];
	/* Convert integer to string */
	_itoa(num, buffer);
	/* Print the string representation of the integer */
	return (_puts(buffer));
}

/**
 * print_unsigned_integer - prints unsigned integers from a va_list
 * @list: va_list of unsigned integers to be printed
 * Return: number of characters printed
 */
int print_unsigned_integer(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	char buffer[50];
	/* Convert integer to string */
	_itoa(num, buffer);
	/* Print the string representation of the unsigned integer */
	return (_puts(buffer));
}

