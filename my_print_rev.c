#include "main.h"



/**
 * print_rev - Function to reverse and print a string.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 1 if successful, -1 if 'str' is NULL.
 */



/*Function print_rev*/
int print_rev(va_list pa, int *pCount)
{
	int i;
	char *str = va_arg(pa, char *); /* Retrieve a string argument from the va_list */

	if (str == NULL) /* Check if the string is NULL */
	{
		return (-1); /* Return -1 to indicate an error (NULL string) */
	}
	else
	{
		/* Loop through the string in reverse order */
		for (i = _strlen(str) - 1; i >= 0; i--)
		{
			_putchar(str[i]); /* Print the character at index 'i' */
			*pCount += 1; /* Increment the character count */
		}
	}

	return (1); /* Return 1 to indicate success */
}
