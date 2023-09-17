#include "main.h"










/************************* PRINTING THE UNSIGNED NUMBER *************************/

/**

 * print_unsigned - This Prints an unsigned number///

 * @types: Provides the arguments///

 * @buffer: This is the Buffer Array to handle the Print///

 * @flags:  This the Calculates active flags///

 * @width: This gets the width///

 * @precision: For Precision specification///

 * @size: For Size specifier///

 * Return: In the end returns the Number of chars printed.

 */










int print_unsigned(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        int i = BUFF_SIZE - 2;

        unsigned long int num = va_arg(types, unsigned long int);


        num = convert_size_unsgnd(num, size);


        if (num == 0)

                buffer[i--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)

        {

                buffer[i--] = (num % 10) + '0';

                num /= 10;

        }


        i++;


        return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}










/************* TO PRINT UNSIGNED NUMBER IN OCTAL  ****************/

/**

 * print_octal - Output an unsigned number in octal notation.

 * @types: List of arguments representing the number to print.

 * @buffer: Buffer array to handle the printing of the number.

 * @flags: Calculates the active flags for formatting.

 * @width: Get the width for formatting.

 * @precision: Specify the precision for formatting.

 * @size: Size specifier to determine the size of the number.

 * Return: The number of characters printed.///

 */









int print_octal(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{


        int i = BUFF_SIZE - 2;

        unsigned long int num = va_arg(types, unsigned long int);

        unsigned long int init_num = num;


        UNUSED(width);


        num = convert_size_unsgnd(num, size);


        if (num == 0)

                buffer[i--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)

        {

                buffer[i--] = (num % 8) + '0';

                num /= 8;

        }


        if (flags & F_HASH && init_num != 0)

                buffer[i--] = '0';


        i++;


        return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}
















/************** THE PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/

/**

 * print_hexadecimal - Output an unsigned number using hexadecimal notation.

 * @types: List of arguments representing the number to print.

 * @buffer: Buffer array to handle the printing of the number.

 * @flags: Calculates the active flags for formatting.

 * @width: Retrieve the width for formatting.

 * @precision: Specify the precision for formatting.

 * @size: Size specifier to determine the size of the number.

 * Return: The number of characters printed.///

 */















int print_hexadecimal(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        return (print_hexa(types, "0123456789abcdef", buffer,

                flags, 'x', width, precision, size));

}



















/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

/**

 * print_hexa_upper - Output an unsigned number using upper hexadecimal notation.

 * @types: List of arguments representing the number to print.

 * @buffer: Buffer array to handle the printing of the number.

 * @flags: Calculate the active flags for formatting.

 * @width: Retrieve the width for formatting.

 * @precision: Specify the precision for formatting.

 * @size: Size specifier to determine the size of the number.

 * Return: The number of characters printed.///

 */







int print_hexa_upper(va_list types, char buffer[],

        int flags, int width, int precision, int size)

{

        return (print_hexa(types, "0123456789ABCDEF", buffer,

                flags, 'X', width, precision, size));

}









/************** THE PRINT HEXADECIMAL NUMBER IN LOWER OR UPPER **************/

/**

 * print_hexa - Output a hexadecimal number in either lowercase or uppercase.

 * @types: List of arguments representing the number to print.

 * @map_to: Array of values used for mapping the number.

 * @buffer: Buffer array to handle the printing of the number.

 * @flags: Calculate the active flags for formatting.

 * @flag_ch: Calculate the active flags for formatting.

 * @width: Retrieve the width for formatting.

 * @precision: Specify the precision for formatting.

 * @size: Size specifier to determine the size of the number.

 * @size: Size specification.

 * Return: The number of characters printed.///

 */







int print_hexa(va_list types, char map_to[], char buffer[],

        int flags, char flag_ch, int width, int precision, int size)

{

        int i = BUFF_SIZE - 2;

        unsigned long int num = va_arg(types, unsigned long int);

        unsigned long int init_num = num;


        UNUSED(width);


        num = convert_size_unsgnd(num, size);


        if (num == 0)

                buffer[i--] = '0';


        buffer[BUFF_SIZE - 1] = '\0';


        while (num > 0)

        {

                buffer[i--] = map_to[num % 16];

                num /= 16;

        }


        if (flags & F_HASH && init_num != 0)

        {

                buffer[i--] = flag_ch;

                buffer[i--] = '0';

        }


        i++;


        return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}
