#include "main.h"



/**
 * print_int - Function to print an integer.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: Always returns 0.
 */


/*Function print_int*/
int print_int(va_list pa, int *pCount)
{
	/* Retrieve the integer argument from the argument list */
	unsigned int num = va_arg(pa, int);

	/* Call the '_putInt' function to print the integer */
	_putInt(num, pCount);

	return (0); /* Return 0 as specified in the function signature */
}
