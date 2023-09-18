#include "main.h"




/**
 * print_hex - Function to print the hexadecimal representation of an unsigned long int.
 * @num: The number to be converted and printed in hexadecimal.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 0 if successful.
 */


/*Function print_hex*/
int print_hex(unsigned long int num, int *pCount)
{
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




/**
 * print_addr - Function to print the address of a pointer.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 1 if the address is NULL, 0 otherwise.
 */



/*Function print_addr*/
int print_addr(va_list pa, int *pCount)
{
    void *addr = va_arg(pa, void *); /* Retrieve a void* argument from the va_list */
    char *str = "(nil)"; /* Define a string for representing NULL address */
    long int num;

    if (addr == NULL) /* Check if the address is NULL */
    {
        _putstr(str, _strlen(str)); /* Print the string "(nil)" */
        (*pCount) += _strlen(str); /* Increment the character count by the length of "(nil)" */
        return (1); /* Return 1 to indicate NULL address */
    }

    _putchar('0'); /* Print '0' character */
    _putchar('x'); /* Print 'x' character */
    (*pCount) += 2; /* Increment the character count by 2 */

    num = (unsigned long int)addr; /* Convert the address to an unsigned long int */

    print_hex(num, pCount); /* Call the print_hex function to print the address in hexadecimal format */

    return (0); /* Return 0 to indicate success */
}

