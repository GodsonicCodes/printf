#include "main.h"


/**
*man_sp - function that gets the function and call it and check
*for signss
*@format: is the string format
*@i: pointer to the index of our format.
*@p: pointer to output struct.
*@Pcount: is the pointer to our counter
*@pArgs: is the pointer to our arguments
*/



void man_sp(const char *format, int *i, struct eq_ch *p,
int *Pcount, va_list pArgs)
{
	int f, k = 3;
	va_list am; /* to copy the pArgs */
	int index = *i;
	int flagg = 0;
	SIGNED flag[] = {{'+', my_postive_sign}, {' ', my_spArgsce_sign}, {'#', my_window_sign},
		{'\0', NULL}};

	va_copy(am, pArgs); /* copy the list of the arguments */
	while (my_signIndex(format[index], flag) != -1)
	{
		for (k = 0; flag[k].ch != '\0'; k++)/* if there are flags */
		{
			if (format[index] == flag[k].ch)
			{
				if (format[index] == '+' && flagg < 2)
					flagg = 1;
				else if (format[index] == '#')
					flagg = 2;
				index++;
				break;
			}
		}
	}
	f = my_spIndex(format[index], p);/* get the index of the sp */
	if (f != -1) /* make sure it match */
	{
		if (flag[k].ch != '\0')
			flag[k].fun(flagg, flag[k].ch, f, am, Pcount);/* print flag */
		p[f].fun(pArgs, Pcount); /*print the argument  */
		*i = index;
	}
	else
	{
		my_putchar('%');
		(*i)--;
		*Pcount += 1;
		return;
	}
}


/**
*_printf - is the function that do same as printf
*@format: is the string format.
*Return: number of character to be printed
*/
int _printf(const char *format, ...)
{
	va_list pArgs; /* points to the arguments list */
	int i, count = 0;
	int *Pcount = &count;
	eqChars type[] = {
		{'s', my_print_str}, {'c', my_print_ch}, {'d', my_print_int},
		{'i', my_print_int}, {'b', my_print_bi}, {'r', my_print_rev},
		{'u', my_print_unsigned}, {'o', my_print_octal}, {'S', my_print_nonch},
		{'x', my_print_lowerhex}, {'X', my_print_upperhex}, {'R', my_print_rot13},
		{'p', my_print_addr}, {'\0', NULL}};

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(pArgs, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			my_putchar(format[i]); /* prints the char */
			*Pcount += 1;
		}
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;/* gets the char after the % */
			man_sp(format, &i, type, Pcount, pArgs);

		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			my_putchar(format[i]);
			*Pcount += 1;
		}
	}
	va_end(pArgs);
	return (count);
}
