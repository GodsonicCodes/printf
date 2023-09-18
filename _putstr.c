#include "main.h"


/**
 * _putstr - Function to print a string to the standard output.
 * @str: Pointer to the string to be printed.
 * @len: Length of the string.
 * Return: -1 if an error occurs, 1 otherwise.
 */



/* _putstr - Function to write a specified number of characters from a string to the standard output */
int _putstr(char *str, int len)
{
	return (write(1, str, len)); /* Use the 'write' system call to print the 'len' characters from the 'str' pointer to the standard output (file descriptor 1) */
}
