#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - Structure for formatting data.
 * @sym: *sym: Pointer to a character string.
 * @fn: func pointer to a function that takes a va_list as an arg.
 */
typedef struct fmt
{
	char *sym;
	int (*fn)(va_list);
} fmt_t;

/**
 * struct flags - Structure storing the status of different flag options.
 * @j: Integer that indicates maximum number of characters to print.
 * @plus: Integer representing plus sign option.
 * @space: Integer representing space option.
 * @hash: Integer representing hash option.
 **/

typedef struct flags
{
	int j;
	int plus;
	int space;
	int hash;
	int l;
	int h;
} flags_t;

typedef struct width
{
	int value;
	int is_zero;
	int is_asterisk;
} width_t;

/**
 * struct function_t - Holds a function pointer and its base value.
 * @base: The base value for the function.
 * @pfn: Pointer to the function.
 **/
typedef struct
{
	int base;
	int (*pfn)(va_list);
} function_t;

/* main */
int _printf(const char *format, ...);

/* getters */
typedef int (*pfn_t)(va_list);
void get_flags(const char *format, flags_t *flags, int *i);
void get_width(const char *format, width_t *width, int *i);
void get_length(const char *format, flags_t *flags, int *i);
pfn_t get_print(const char *format);
pfn_t get_conversion(const char *format, int *i, va_list args,
					 flags_t *flags, width_t *width);

/* handlers */
void process_flags(flags_t *flags, va_list args_flags,
				 pfn_t pfn, int *printed);
void process_width(width_t *width, va_list args_width,
				 pfn_t pfn, int *printed);
void process_length(flags_t *flags, va_list args_flags,
				  pfn_t pfn, int *printed);

/* print_chars */
int print_character(va_list list);
int print_string(va_list list);
int print_percent(va_list list);

/* print_numbers */
int print_integer(va_list list);
int print_unsigned_integer(va_list list);

/* print_bases */
int print_binary(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
int print_addrs(va_list list);

/* print_customs */
int print_STR(va_list list);
int print_rev(va_list list);
int print_rot13(va_list list);

/* utils */
unsigned int _strlen(char *s);
void reverse_str(char s[]);
void _itoa(long n, char s[]);
int to_base_n(unsigned long num, int base, char s[]);
int num_len_base(long num, int base);

/* writers */
int _putchar(char c);
int _puts(char *str);

#endif

