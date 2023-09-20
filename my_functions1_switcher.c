#include "main.h"



/**
 * r_specifier - Handles the 'r' specifier.
 *
 * This function processes the 'r' specifier and prints the reversed string.
 *
 * @param par:    The parameter list containing the string to reverse.
 * @param count:  Pointer to the count of characters printed.
 *
 * @return:       Always returns 1.
 */


/*Function r_specifier*/
int r_specifier(va_list par, int *count)
{
    const char *par_str = va_arg(par, char *);

    // Duplicate the pointer, so we can check if the string is NULL after reading it from va_list
    par_str = va_arg(par, char *);

    // If the string is NULL, print "(null)" and update the count
    if (par_str == NULL)
    {
        (*count) += _puts("(null)");
        return (1);
    }

    // Print the reversed string and update the count
    (*count) += _revputs(par_str);
    return (1);
}




/**
 * b_specifier - Handles the 'b' specifier.
 *
 * This function processes the 'b' specifier and prints an integer in binary format.
 *
 * @param par:    The parameter list containing the integer to print in binary.
 * @param count:  Pointer to the count of characters printed.
 *
 * @return:       Always returns 1.
 */



/*Function b_specifier*/
int b_specifier(va_list par, int *count)
{
    int bin = va_arg(par, int);

    // Print the integer in binary format and update the count
    (*count) += print_binary(bin);
    return (1);
}



/**
 * u_specifier - Handles the 'u' specifier.
 *
 * This function processes the 'u' specifier and prints an unsigned integer.
 *
 * @param par:    The parameter list containing the unsigned integer.
 * @param count:  Pointer to the count of characters printed.
 *
 * @return:       Always returns 1.
 */



/*Function u_specifier*/
int u_specifier(va_list par, int *count)
{
    unsigned int par_int = va_arg(par, unsigned int);

    // Print the unsigned integer and update the count
    (*count) += print_unsignedd(par_int);
    return (1);
}




/**
 * o_specifier - Handles the 'o' specifier.
 *
 * This function processes the 'o' specifier and prints an integer in octal format.
 *
 * @param par:    The parameter list containing the integer to print in octal.
 * @param count:  Pointer to the count of characters printed.
 *
 * @return:       Always returns 1.
 */


/*Function 0_specifier*/
int o_specifier(va_list par, int *count)
{
    int par_int = va_arg(par, unsigned int);

    // Print the integer in octal format and update the count
    (*count) += print_octal(par_int);
    return (1);
}




/**
 * x_specifier - Handles the 'x' specifier.
 *
 * This function processes the 'x' specifier and prints an integer in hexadecimal format.
 *
 * @param par:    The parameter list containing the integer to print in hexadecimal.
 * @param count:  Pointer to the count of characters printed.
 *
 * @return:       Always returns 1.
 */


/*Function 0_specifier*/
int x_specifier(va_list par, int *count)
{
    int par_int = va_arg(par, unsigned int);

    // Print the integer in hexadecimal format and update the count
    (*count) += print_hex(par_int, 0);
    return (1);
}

