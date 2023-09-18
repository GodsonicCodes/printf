#include "main.h"




/**
 * print_upperhex - Function to print hexadecimal numbers in upper case.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: The count of characters printed.
 */



/*Function print_upperhex*/
int print_upperhex(va_list pa, int *pCount)
{
    unsigned int num = va_arg(pa, unsigned int); /* Retrieve an unsigned int argument from the va_list */
    char buffer[32]; /* Initialize a character buffer to store hexadecimal digits */
    int i;
    int count = 0; /* Initialize counters for the loop and total character count */
    char hex_digits[] = "0123456789ABCDEF"; /* Define an array of hexadecimal digits */

    i = 0; /* Initialize the loop counter */

    if (num == 0) /* Check if the number is 0 */
    {
        _putchar('0'); /* Print '0' character */
        (*pCount)++; /* Increment the character count */
        return (1); /* Return 1 to indicate 1 character printed */
    }

    while (num > 0) /* Loop to extract hexadecimal digits from the number */
    {
        buffer[i] = hex_digits[num % 16]; /* Get the hexadecimal digit and store it in the buffer */
        num /= 16; /* Remove the last hexadecimal digit from the number */
        i++; /* Move to the next position in the buffer */
    }

    i--; /* Decrement 'i' to point to the last character in the buffer */

    while (i >= 0) /* Loop to print the hexadecimal digits in reverse order */
    {
        _putchar(buffer[i]); /* Print the character from the buffer */
        i--; /* Move to the previous character */
        (*pCount)++; /* Increment the character count */
        count++; /* Increment the local count variable */
    }

    return (count); /* Return the total count of characters printed */
}

