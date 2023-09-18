#include "main.h"


/**
 * _strlen - Function to determine the length of a string.
 * @s: Pointer to the input string.
 * Return: The length of the string.
 */


/* _strlen - Function to calculate the length of a string */
int _strlen(char *s)
{
	int lenth = 0; /* Initialize 'lenth' to zero to store the string length */

	while (*s != '\0') /* Iterate through the characters in the string until the null terminator '\0' is reached */
	{
		lenth++; /* Increment 'lenth' for each character encountered */
		s++; /* Move to the next character in the string */
	}

	return (lenth); /* Return the total length of the string */
}
