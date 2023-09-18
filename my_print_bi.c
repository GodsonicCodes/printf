#include "main.h"




/**
 * print_bi - Function to print a binary representation of an unsigned int.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed (unused in this function).
 * Return: Always returns 0.
 */



/*Function print_bi*/
int print_bi(va_list pa, __attribute__((unused)) int *pCount)
{
    unsigned int num = va_arg(pa, unsigned int); /* Retrieve an unsigned int argument from the va_list */
    char buffer[32]; /* Initialize a character buffer to store binary digits */
    int i;

    i = 0; /* Initialize the loop counter */

    if (num == 0) /* Check if the number is 0 */
    {
        _putchar('0'); /* Print '0' character */
        /* Increment the character count (unused in this function) */
        (*pCount)++;
        return (1); /* Return 1 to indicate 1 character printed */
    }

    /* Divide the number by 2 and store binary digits in the buffer */
    for (i = 0; num > 0; i++)
    {
        buffer[i] = (num % 2) + '0'; /* Get the binary digit (0 or 1) and store it in the buffer */
        num /= 2; /* Divide the number by 2 to remove the last binary digit */
    }

    i--; /* Decrement 'i' to point to the last character in the buffer */

    /* Print the binary digits in reverse order */
    for (; i >= 0; i--)
    {
        _putchar(buffer[i]); /* Print the character from the buffer */
        /* Increment the character count (unused in this function) */
        (*pCount)++;
    }

    return (0); /* Return 0 to indicate success */
}
