#include "main.h"


/**
*my_print_str - function that prints a string
*@pArgs: points to the list of arguments
*@Pcount: is the pointer to the counter
*Return: 1 if no error , -1 otherwise
*/

int my_print_str(va_list pArgs, int *Pcount)
{
	char *str;

	str = va_arg(pArgs, char *);
	if (str == NULL)
		str = "(null)";

	if (my_putstr(str, my_strlen(str)) != -1)
		*Pcount += my_strlen(str);
	else
		return (-1);

	return (1);
}


/**
*my_print_ch - a function that prints a character.
*@pArgs: points to the list of arguments.
*@Pcount: is the pointer to the counter
*Return: 1 if sucess , -1 otherwise
*/


int my_print_ch(va_list pArgs, int *Pcount)
{
	if (my_putchar((unsigned char)va_arg(pArgs, int)) != -1)
		*Pcount += 1;
	else
		return (-1);

	return (1);
}
