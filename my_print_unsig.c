#include "main.h"



/**
 * print_unsigned - Function to print unsigned numbers.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 0.
 */


/*Function print_unsigned*/
int print_unsigned(va_list pa, int *pCount)
{
    unsigned int num = va_arg(pa, unsigned int); /* Retrieve an unsigned int argument from the va_list */
    char buffer[32]; /* Initialize a character buffer to store digits as strings */
    int i, count = 0; /* Initialize counters for the loop and total character count */

    i = 0; /* Initialize the loop counter */

    if (num == 0) /* Check if the number is 0 */
    {
        _putchar('0'); /* Print '0' character */
        count++; /* Increment the character count */
    }
    else
    {
        while (num > 0) /* Loop to extract digits from the number */
        {
            buffer[i] = (num % 10) + '0'; /* Convert the digit to a character and store it in the buffer */
            num /= 10; /* Remove the last digit from the number */
            i++; /* Move to the next position in the buffer */
        }
        i--; /* Decrement 'i' to point to the last character in the buffer */

        while (i >= 0) /* Loop to print the digits in reverse order */
        {
            _putchar(buffer[i]); /* Print the character from the buffer */
            i--; /* Move to the previous character */
            count++; /* Increment the character count */
        }
    }

    *pCount += count; /* Update the total character count */
    return (0); /* Return 0 to indicate success */
}
