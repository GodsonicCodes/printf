#include "main.h"




/**
 * print_octal - Function to print the octal representation of an unsigned int.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: The number of characters printed.
 */



/*Function print_octal*/
int print_octal(va_list pa, int *pCount)
{
    unsigned int num = va_arg(pa, unsigned int); /* Retrieve an unsigned int argument from the va_list */
    char buffer[32]; /* Initialize a character buffer to store octal digits */
    int i;

    i = 0; /* Initialize the loop counter */

    if (num == 0) /* Check if the number is 0 */
    {
        _putchar('0'); /* Print '0' character */
        (*pCount)++; /* Increment the character count */
        return (1); /* Return 1 to indicate 1 character printed */
    }

    while (num > 0) /* Loop to extract octal digits from the number */
    {
        buffer[i] = (num % 8) + '0'; /* Get the octal digit and store it in the buffer */
        num /= 8; /* Remove the last octal digit from the number */
        i++; /* Move to the next position in the buffer */
    }

    i--; /* Decrement 'i' to point to the last character in the buffer */

    while (i >= 0) /* Loop to print the octal digits in reverse order */
    {
        _putchar(buffer[i]); /* Print the character from the buffer */
        i--; /* Move to the previous character */
        (*pCount)++; /* Increment the character count */
    }

    return (i); /* Return the total number of characters printed */
}
