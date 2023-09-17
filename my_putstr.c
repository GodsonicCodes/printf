#include "main.h"


/**
*my_putstr - function that prints a sting
*
*@str: this is the pointer to the str we want to print
*
*@Length: lenth of the string
*
*Return: will return 1 if there is no error and -1 if there is an error
*/


int my_putstr(char *str, int Length)
{
	return (write(1, str, Length));
}
