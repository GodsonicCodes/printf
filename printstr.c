#include "main.h"




/**
 * print_str - Function to print a string.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 1 if successful, -1 otherwise.
 */


/* Function print_str*/
int print_str(va_list pa, int *pCount)
{
	char *str; /*Character str*/

	str = va_arg(pa, char *);

	/* Check if the string is NULL, and if so, assign a default value */
	if (str == NULL)
		str = "(null)";

	/* Call the '_putstr' function to print the string and update the character count */
	if (_putstr(str, _strlen(str)) != -1)
		*pCount += _strlen(str);
	else
		return (-1); /* Return -1 in case of an error */

	return (1); /* Return 1 to indicate success */
}



/**
 * print_ch - Function to print a character.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 1 if successful, -1 otherwise.
 */


/*Function print_ch*/
int print_ch(va_list pa, int *pCount)
{
	/* Call the '_putchar' function to print a character and update the character count */
	if (_putchar((unsigned char)va_arg(pa, int)) != -1)
		*pCount += 1;
	else
		return (-1); /* Return -1 in case of an error */

	return (1); /* Return 1 to indicate success */
}

