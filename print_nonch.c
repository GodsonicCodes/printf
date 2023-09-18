#include "main.h"




/**
 * put_hex_upper - Function to print a hexadecimal number in uppercase.
 * @num: The number to be printed in hexadecimal.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 1 if the number is 0, 0 otherwise.
 */



/*Function put_hex_upper*/
int put_hex_upper(int num, int *pCount)
{
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

    return (0); /* Return 0 to indicate success */
}




/**
 * print_nonch - Function to print non-printable characters in hexadecimal format (uppercase).
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 0.
 */


/*Function print_nonch*/
int print_nonch(va_list pa, int *pCount)
{
    char *str = va_arg(pa, char *); /* Retrieve a char* argument from the va_list */
    int i;

    if (str == NULL)
        str = "(null)"; /* Replace NULL string with "(null)" */

    for (i = 0; str[i] != '\0'; i++) /* Loop through the characters in the string */
    {
        if ((str[i] > 0 && str[i] < 32) || str[i] >= 127) /* Check for non-printable characters */
        {
            _putchar('\\'); /* Print backslash */
            _putchar('x'); /* Print 'x' character */
            (*pCount) += 2; /* Increment the character count by 2 */

            if (str[i] < 16) /* Check if the character is less than 16 (single-digit hexadecimal) */
            {
                _putchar('0'); /* Print '0' character */
                (*pCount)++; /* Increment the character count */
            }

            put_hex_upper(str[i], pCount); /* Call the put_hex_upper function to print the character in hexadecimal format */
        }
        else
        {
            _putchar(str[i]); /* Print the character as it is */
            (*pCount)++; /* Increment the character count */
        }
    }

    return (0); /* Return 0 to indicate success */
}

