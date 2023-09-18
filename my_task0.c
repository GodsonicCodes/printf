#include "main.h"



/* Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
*/


int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            //The Regular character, print it
            write(1, format, 1);
            printed_chars++;
        }
        else
        {
            format++; // Move past, '%'
            if (*format == '\0')
                break; // Ignore a trailing '%' character

            if (*format == 'c')
            {
                // Handle The character specifier
                char c = va_arg(args, int); // char is promoted to int
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                // Handle The string specifier
                char *str = va_arg(args, char *);
                if (str == NULL)
                    str = "(null)";
                while (*str)
                {
                    write(1, str, 1);
                    str++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                // Handle The literal '%'
                write(1, "%", 1);
                printed_chars++;
            }
            else
            {
                //For Unsupported specifier, just print the '%'
                write(1, "%", 1);
                printed_chars++;
                if (*format != '\0')
                {
                    write(1, format, 1);
                    printed_chars++;
                }
            }
        }
        format++;
    }

    va_end(args);

    return printed_chars;
}

