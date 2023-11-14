#include "main.h"

/**
 * print_character - prints a character from a va_list arguments.
 * @list: va_list arguments.
 * Return: count of printed characters.
 */

int print_character(va_list list)
{
        _putchar(va_arg(list, int));
        return (1);
}

/**
 * print_string - prints a string from a va_list.
 * @list: the va_list containing the string to be printed.
 * Return: count of printed characters.
 */

int print_string(va_list list)
{
        int count = 0;
        char *str;

        str = va_arg(list, char *);
        if (!str)
                str = "(null)";

        for (; str[count]; count++)
                _putchar(str[count]);

        return (count);
}

/**
 * print_percent - prints a percent sign.
 * @list: list of arguments (unused).
 * Return: count of printed characters.
 */

int print_percent(va_list list)
{
        (void)(list);
        _putchar('%');
        return (1);
}

