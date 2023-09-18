#include "main.h"




/**
 * print_rot13 - Function to print a string in ROT13 encoding.
 * @pa: Pointer to the list of arguments.
 * @pCount: Pointer to a counter for characters printed.
 * Return: 0.
 */



/*Function print_rot13*/
int print_rot13(va_list pa, int *pCount)
{
	char *str = va_arg(pa, char *); /* Retrieve a string argument from the va_list */
	int i, j;
	char a[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
		'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
		'W', 'X', 'Y', 'Z'};
	char b[] = {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y',
		'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
		'l', 'm', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
		'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M'};

	if (str == NULL)
	{
		str = "(null)"; /* Replace NULL string with a default value */
		_putstr(str, _strlen(str)); /* Print the default string */
		*pCount += _strlen(str); /* Update character count */
		return (-1); /* Return -1 to indicate an error (NULL string) */
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; (a[j] != '\0' && str[i] != a[j]);)
		{
			j++; /* Find the corresponding ROT13 character */
		}

		if (str[i] == a[j])
		{
			_putchar(b[j]); /* Print the ROT13 character */
			*pCount += 1; /* Increment character count */
		}
		else
		{
			_putchar(str[i]); /* Print the original character */
			*pCount += 1; /* Increment character count */
		}
	}

	return (0); /* Return 0 to indicate success */
}

