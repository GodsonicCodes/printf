#include "main.h"



/**
 * _putInt - Function to print an integer to the standard output.
 * @num: The integer to be printed.
 * @pCount: Pointer to a counter to track the number of integers printed.
 */


/* _putInt - Function to print an integer to the standard output */
void _putInt(unsigned int num, int *pCount)
{
	/* Check if it's a negative number */
	if ((int)num < 0)
	{
		_putchar('-'); /* Print a minus sign for negative numbers */
		*pCount += 1; /* Increment the character count */
		num *= -1; /* Make the number positive */
	}
	/* Check if the number is not a single digit */
	if (num / 10)
		_putInt(num / 10, pCount); /* Recursively call the function for non-single digit numbers */
	/* Print the digit as an ASCII character by adding 48 ('0') */
	_putchar(num % 10 + '0'); /* Print the last digit of the number */
	*pCount += 1; /* Increment the character count */
}
