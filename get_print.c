#include "main.h"

/**
 * get_print - Returns a pointer to the appropriate print
 * function based on the format specifier.
 * @format: The format specifier.
 * Return: pointer to the appropriate print function,
 * or NULL if no match is found.
 */
pfn_t get_print(const char *format)
{
        int i = 0;
        fmt_t fmt_types[] = {
                {"c", print_character},
                {"s", print_string},
                {"%", print_percent},
                {"d", print_integer},
                {"i", print_integer},
                {"u", print_unsigned_integer},
                {"b", print_binary},
                {"o", print_octal},
                {"x", print_hex},
                {"X", print_HEX},
                {"p", print_addrs},
                {"S", print_STR},
                {"r", print_rev},
                {"R", print_rot13},
                {NULL, NULL}};

        for (; fmt_types[i].sym; i++)
        {
                if (*format == *(fmt_types[i].sym))
                {
                        return (fmt_types[i].fn);
                }
        }
        return (NULL);
}
