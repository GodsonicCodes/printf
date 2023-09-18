#include "main.h"


/**
 * postive_sign - Function to print the '+' flag in a format specifier.
 * @flag: The flag character ('+').
 * @ch: The character to overwrite the flag ('+').
 * @j: The index of the argument.
 * @ap: The copy of the argument list.
 * @pCount: Pointer to the count of characters printed.
 */




/* postive_sign - Function to handle the '+' flag in a format specifier */
void postive_sign(int flag, char ch, int j, va_list ap, int *pCount)
{
	/* Check if the flag is less than 2 or if 'j' corresponds to specific format specifiers */
	if (flag < 2 || (j == 2 || j == 3 || j == 12))
	{
		/* Check if the 'ch' is '+' and 'j' corresponds to specific format specifiers */
		if (ch == '+' && (j == 2 || j == 3 || j == 12))
		{
			/* Check if the argument is greater than or equal to 0 or if 'j' is 12 */
			if (va_arg(ap, int) >= 0 || j == 12)
			{
				_putchar('+'); /* Print the plus sign */
				*pCount += 1; /* Increment the character count */
			}
		}
	}
	else
	{
		window_sign(flag, '#', j, ap, pCount); /* Call another function to handle the '#' flag */
	}
}



/**
 * space_sign - Function to print the space flag in a format specifier.
 * @flag: The flag character (' ').
 * @ch: The character to overwrite the flag (' ').
 * @j: The index of the argument.
 * @ap: The copy of the argument list.
 * @pCount: Pointer to the count of characters printed.
 */




/* space_sign - Function to handle the ' ' (space) flag in a format specifier */
void space_sign(int flag, char ch, int j, va_list ap, int *pCount)
{
	/* Check if 'ch' is a space character and 'j' corresponds to specific format specifiers, and 'flag' is 0 */
	if ((ch == ' ' && (j == 2 || j == 3 || j == 12)) && flag == 0)
	{
		/* Check if the argument is greater than or equal to 0 or if 'j' is 12 */
		if (va_arg(ap, int) >= 0 || j == 12)
		{
			_putchar(' '); /* Print a space character */
			*pCount += 1; /* Increment the character count */
		}
	}
	/* Check if 'flag' is less than or equal to 2 and 'j' corresponds to specific format specifiers */
	else if (flag <= 2 && (j == 2 || j == 3 || j == 12))
	{
		_putchar('+'); /* Print a plus sign */
		*pCount += 1; /* Increment the character count */
	}
	/* Check if 'flag' is 2 and 'j' does not correspond to specific format specifiers */
	else if (flag == 2 && !(j == 2 || j == 3 || j == 12))
	{
		window_sign(flag, '#', j, ap, pCount); /* Call another function to handle the '#' flag */
	}
}




/**
 * window_sign - Function to handle the '#' (hash) flag in a format specifier.
 * @flag: The flag character ('#').
 * @ch: The character to overwrite the flag ('#').
 * @j: The index of the argument.
 * @ap: The copy of the argument list.
 * @pCount: Pointer to the count of characters printed.
 */



/* window_sign - Function to handle the '#' (hash) flag in a format specifier */
void window_sign(int flag, char ch, int j, va_list ap, int *pCount)
{
	/* Check if the next integer argument is not equal to zero */
	if (va_arg(ap, int) != 0)
	{
		/* Check if 'flag' is greater than 1 and 'j' is not one of specific format specifiers */
		if (flag > 1 && !(j == 2 || j == 3 || j == 12))
		{
			/* Check if 'ch' is '#' and 'j' is 7 */
			if (ch == '#' && j == 7)
			{
				_putchar('0'); /* Print '0' character */
				*pCount += 1; /* Increment the character count */
			}
			/* Check if 'ch' is '#' and 'j' is 9 */
			else if (ch == '#' && j == 9)
			{
				_putchar('0'); /* Print '0' character */
				_putchar('x'); /* Print 'x' character */
				*pCount += 2; /* Increment the character count by 2 */
			}
			/* Check if 'ch' is '#' and 'j' is 10 */
			else if (ch == '#' && j == 10)
			{
				_putchar('0'); /* Print '0' character */
				_putchar('X'); /* Print 'X' character */
				*pCount += 2; /* Increment the character count by 2 */
			}
		}
		/* Check if 'flag' is less than 2 and 'j' corresponds to specific format specifiers */
		else if (flag < 2 && (j == 2 || j == 3 || j == 12))
		{
			_putchar('+'); /* Print a plus sign */
			*pCount += 1; /* Increment the character count */
		}
	}
}


