#include "main.h"


/**
 * _putchar - Function that prints a single character to the standard output.
 * @sp_ch: The character to be printed on the terminal.
 * Return: -1 if there is an error, 1 otherwise.
 */


/* _putchar - Function to write a single character to the standard output */
int _putchar(char sp_ch)
{
    return (write(1, &sp_ch, 1)); /* Use the 'write' system call to print a character ('sp_ch') to the standard output (file descriptor 1) */
}
