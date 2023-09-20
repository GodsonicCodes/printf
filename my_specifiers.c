#include "main.h"



/**
 * specifiers - Handle format specifiers in our custom printf implementation.
 *
 * This function processes format specifiers within the format string and
 * performs appropriate actions based on each specifier.
 *
 * @param par_list:   The va_list of variable arguments.
 * @param format:     The format string containing specifiers.
 * @param i:          Pointer to the current position in the format string.
 * @param count:      Pointer to the count of characters printed.
 */



/*Function Specifiers*/
void specifiers(va_list par_list, const char *format, int *i, int *count)
{
    char parameter, *par_str;
    int par_int, status;

    // Switch statement to handle different format specifiers
    switch (format[*i])
    {
        // Case 'c' for character
        case 'c':
            // Retrieve the next argument from the parameter list as an int (character)
            parameter = va_arg(par_list, int);
            // Call _putchar to print the character and increment the count
            (*count) += _putchar(parameter);
            break;


        // Case 's' for string
        case 's':
            // Retrieve the next argument from the parameter list as a char pointer (string)
            par_str = va_arg(par_list, char *);
            // Call print_null_str to handle printing the string (including NULL) and update the count
            print_null_str(par_str, count);
            break;


        // Case '%' for percent symbol
        case '%':
            // Print a percent symbol and increment the count
            (*count) += _putchar('%');
            break;


        // Cases 'd' and 'i' for decimal and integer
        case 'd':
        case 'i':
            // Retrieve the next argument from the parameter list as an int
            par_int = va_arg(par_list, int);
            // Call print_num to print the integer and update the count
            (*count) += print_num(par_int);
            break;


        // Default case for handling additional format specifiers
        default:
            // Call morespec to handle additional format specifiers and get the status
            status = morespec(par_list, format, i, count);
            // If morespec returns 0 (no additional handling), print '%' and the character itself
            if (status == 0)
            {
                (*count) += _putchar('%');
                (*count) += _putchar(format[*i]);
            }
    }
}
