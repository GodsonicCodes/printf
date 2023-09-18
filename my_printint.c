#include "main.h"


/**
*my_print_int - is the function that prints an integer
*@pArgs: this points to the list of arguments
*@Pcount: is the pointer to counter
*Return: 0
*/


int my_print_int(va_list pArgs, int *Pcount)
{
	unsigned int  numb = va_arg(pArgs, int);

	my_putInt(numb, Pcount);

	return (0);
}
