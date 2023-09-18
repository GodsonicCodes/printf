#include "main.h"




/**
 * print_lowerhex - Function to print lowercase hexadecimal representation of an unsigned int.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: Number of characters printed.
 */



/*Function print_lowerhex*/
int print_lowerhex(va_list pa, int *pCount)
{
    unsigned int num = va_arg(pa, unsigned int); /* Retrieve an unsigned int argument from the va_list */
    char buffer[32]; /* Initialize a character buffer to store hexadecimal digits */
    int i;

    i = 0; /* Initialize the loop counter */

    if (num == 0) /* Check if the number is 0 */
    {
        _putchar('0'); /* Print '0' character */
        (*pCount)++; /* Increment the character count */
        return (1); /* Return 1 to indicate 1 character printed */
    }

    while (num > 0) /* Loop to extract hexadecimal digits from the number */
    {
        buffer[i] = (num % 16) + (num % 16 > 9 ? 'a' - 10 : '0'); /* Get the hexadecimal digit and store it in the buffer */
        num /= 16; /* Remove the last hexadecimal digit from the number */
        i++; /* Move to the next position in the buffer */
    }

    i--; /* Decrement 'i' to point to the last character in the buffer */

    while (i >= 0) /* Loop to print the hexadecimal digits in reverse order */
    {
        _putchar(buffer[i]); /* Print the character from the buffer */
        i--; /* Move to the previous character */
        (*pCount)++; /* Increment the character count */
    }

    return (0); /* Return 0 to indicate success */
}

