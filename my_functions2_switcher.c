#include "main.h"



/**
 * X_specifier - Handles the 'X' specifier.
 *
 * This function processes the 'X' specifier and prints an integer in hexadecimal
 * format with uppercase letters (A-F).
 *
 * @param par:    The parameter list containing the integer to print in hexadecimal.
 * @param count:  Pointer to the count of characters printed.
 *
 * @return:       Always returns 1.
 */



/*Function x_specifier*/
int X_specifier(va_list par, int *count)
{
    int par_int = va_arg(par, unsigned int);

    // Print the integer in hexadecimal format with uppercase letters and update the count
    (*count) += print_hex(par_int, 1);
    return (1);
}



/**
 * S_specifier - Handles the 'S' specifier.
 *
 * This function processes the 'S' specifier and prints a custom string.
 *
 * @param par:    The parameter list containing the string to print.
 * @param count:  Pointer to the count of characters printed.
 *
 * @return:       Always returns 1.
 */



/*Function S_specifier*/
int S_specifier(va_list par, int *count)
{
    const char *par_str = va_arg(par, char *);

    // If the string is NULL, print "(null)" and update the count
    if (par_str == NULL)
    {
        (*count) += _puts("(null)");
        return (1);
    }

    // Print the custom string and update the count
    (*count) += print_custom_string(par_str);
    return (1);
}

