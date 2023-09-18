#include "main.h"


/**
*my_putInt - is a function that prints an integer
*@numb: is the integer we want to print
*@Pcount: is the pointer to the counter to know numb of int being printed
*/


void my_putInt(unsigned int numb, int *Pcount)
{
	/* if its a negative numb */
	if ((int)numb < 0)
	{
		my_putchar('-');
        *Pcount += 1;
        numb *= -1;
	}
	/* checks if the numb is not one digit */
	if (numb / 10)
		my_putInt(numb / 10, Pcount); /* calls the function again if not one digit */
	/* prints the numb in ascii by adding 48  */
	my_putInt(numb % 10 + '0');
	*Pcount += 1;
}
