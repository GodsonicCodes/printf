#include "main.h"



/**
 * call_sp - Function that retrieves a function pointer, calls it, and checks for errors.
 * @format: The format string.
 * @i: Pointer to the index within our format string.
 * @p: Pointer to our custom data structure.
 * @pCount: Pointer to our character count.
 * @pa: Pointer to our variadic arguments.
 */




void call_sp(const char *format, int *i, struct sp_char *p,
    int *pCount, va_list pa)
{
    int j, k = 3; /* Initialize variables 'j' and 'k' with initial values */
    int index = *i; /* Initialize 'index' with the current position in the 'format' string */
    va_list ap; /* Declare a new va_list 'ap' to copy the 'pa' argument list */
    int flagg = 0; /* Initialize 'flagg' to 0 to track flag presence */
    sign flag[] = {{'+', postive_sign}, {' ', space_sign}, {'#', window_sign},
        {'\0', NULL}}; /* Define an array of 'sign' structures for flag handling */

    va_copy(ap, pa); /* Copy the 'pa' argument list into 'ap' */
    while (signIndex(format[index], flag) != -1)
    {
        for (k = 0; flag[k].ch != '\0'; k++)/* Loop to check for flags in 'format' string */
        {
            if (format[index] == flag[k].ch)
            {
                if (format[index] == '+' && flagg < 2) /* Check for the '+' flag */
                    flagg = 1; /* Set 'flagg' to 1 */
                else if (format[index] == '#') /* Check for the '#' flag */
                    flagg = 2; /* Set 'flagg' to 2 for window flag */
                index++; /* Move to the next character in 'format' */
                break; /* Exit the loop */
            }
        }
    }
    j = spIndex(format[index], p);/* Get the index of the special character in 'p' */
    if (j != -1) /* Check if a valid index was found */
    {
        if (flag[k].ch != '\0') /* Check if there was a flag */
            flag[k].fun(flagg, flag[k].ch, j, ap, pCount);/* Call the flag handling function */
        p[j].fun(pa, pCount); /* Call the corresponding argument handling function */
        *i = index; /* Update 'i' to the current position */
    }
    else
    {
        _putchar('%'); /* Print a '%' character */
        (*i)--; /* Decrement 'i' to go back to the '%' character in 'format' */
        *pCount += 1; /* Increment the character count */
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

