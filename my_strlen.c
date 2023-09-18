#include "main.h"


/**
* my_strlen - gets the length of the string
* @g: is the string
* Return: returns the length at the end
*/


int my_strlen(char *g)
{
	int lent = 0;

	while (*g != '\0')
	{
		lent++;
		g++;
	}

	return (lent);
}
