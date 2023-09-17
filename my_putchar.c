#include "main.h"


/**
 * my_putchar - This prints character
 *
 * @p: is the character to be printed
 *
 * Return: returns the number of characters printed to standard output
 * That is 1 and -1 if there is an error.
 */


int my_putchar(char p)
{
	return (write(1, &p, 1)); /* 1 for write on the standard output*/
}
