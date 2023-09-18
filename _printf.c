#include "main.h"



/**
 * call_sp - Function that retrieves a function pointer, calls it, and checks for errors.
 * @format: The format string.
 * @i: Pointer to the index within our format string.
 * @p: Pointer to our custom data structure.
 * @pCount: Pointer to our character count.
 * @pa: Pointer to our variadic arguments.
 */




void call_sp(const char *format, int *i, struct sp_char *p, int *pCount, va_list pa) /*Prototype */
{
    int j, k = 3; ?/*the variables we are using */
    va_list ap; /* Create a copy of the va_list to preserve the original */
    int index = *i; /* Initialize 'index' with the current position in the 'format' string */
    int flagg = 0; /* Initialize 'flagg' to 0 to keep track of special flags */
    sign flag[] = {{'+', postive_sign}, {' ', space_sign}, {'#', window_sign}, {'\0', NULL}};

    va_copy(ap, pa); /* Copy the variadic argument list to 'ap' to avoid altering the original */

    /* Loop through the characters in 'format' until no matching flags are found */
    while (signIndex(format[index], flag) != -1)
    {
        for (k = 0; flag[k].ch != '\0'; k++) /* Check for supported flags */
        {
            if (format[index] == flag[k].ch)
            {
                if (format[index] == '+' && flagg < 2)
                    flagg = 1; /* Set 'flagg' to 1 for '+' flag */
                else if (format[index] == '#')
                    flagg = 2; /* Set 'flagg' to 2 for '#' flag */
                index++; /* Move to the next character in 'format' */
                break; /* Exit the loop after finding a matching flag */
            }
        }
    }

    j = spIndex(format[index], p); /* Get the index of the special character in 'p' array */

    if (j != -1) /* Check if a matching special character was found */
    {
        if (flag[k].ch != '\0')
            flag[k].fun(flagg, flag[k].ch, j, ap, pCount); /* Call flag function if a flag is present */
        p[j].fun(pa, pCount); /* Call the appropriate function to handle the argument */
        *i = index; /* Update 'i' with the new index position */
    }
    else
    {
        _putchar('%'); /* Print '%' character as it's not a valid specifier */
        (*i)--; /* Decrement 'i' to reprocess the '%' character */
        (*pCount) += 1; /* Increment the character count */
        return; /* Return from the function */
    }
}



/**
 * _printf - Function that replicates the functionality of printf.
 * @format: The format string.
 * Return: The number of characters printed.
 */


int _printf(const char *format, ...)
{
	va_list pa; /* Declare a va_list variable to handle variadic arguments */
	int i, count = 0; /* Initialize 'i' for looping and 'count' for character count */
	int *pCount = &count; /* Create a pointer to 'count' for updating character count */


	spChar type[] = {
		{'s', print_str}, {'c', print_ch}, {'d', print_int},
		{'i', print_int}, {'b', print_bi}, {'r', print_rev},
		{'u', print_unsigned}, {'o', print_octal}, {'S', print_nonch},
		{'x', print_lowerhex}, {'X', print_upperhex}, {'R', print_rot13},
		{'p', print_addr}, {'\0', NULL}}; /* Initialize an array of supported specifiers and their associated functions */


	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1); /* Check for invalid or empty format strings */

	va_start(pa, format); /* Initialize the va_list 'pa' with variadic arguments */
	for (i = 0; format[i] != '\0'; i++) /* Loop through the characters in 'format' */
	{
		if (format[i] != '%')
		{
			_putchar(format[i]); /* Print the character if it's not '%' */
			*pCount += 1; /* Increment the character count */
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++; /* Move to the character after '%' */
			call_sp(format, &i, type, pCount, pa); /* Call a function to handle the specifier */
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++; /* Move to the character after the first '%' */
			_putchar(format[i]); /* Print the second '%' character */
			*pCount += 1; /* Increment the character count */
		}
	}
	va_end(pa); /* Clean up the va_list */
	return (count); /* Return the total character count */
}
