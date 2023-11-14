#include "main.h"

/**
 * get_conversion - Retrieve the conversion function for a
 * given format specifier.
 * @format: The format string.
 * @current_index: Pointer to the current index in the format string.
 * @args: va_list of arguments.
 * @flags: Pointer to a flags_t struct containing any flags found.
 * @width: Pointer to a width_t struct containing any widths found.
 * Return: A pointer to the conversion function.
 */

pfn_t get_conversion(const char *format, int *current_index,
		va_list args, flags_t *flags, width_t *width)
{
	int (*conversion_func)(va_list);
	/* Extract flags, width, and length modifiers */
	get_flags(format, flags, current_index);
	get_width(format, width, current_index);
	get_length(format, flags, current_index);
	/* If width is specified with '*', retrieve it from va_arg */
	if (width->is_asterisk)
		width->value = va_arg(args, int);

	/* Get the conversion function based on the current specifier */
	conversion_func = get_print(&format[*current_index]);
	return (conversion_func);
}

