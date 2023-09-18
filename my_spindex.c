#include "main.h"


/**
*my_spIndex - function that the index of the special char from the
*array of strings
*@ch: is the character we want to know its index
*@r: is the pointer to array of struct that we search in
*Return: index, or NULL for otherwise
*/


int my_spIndex(char ch, struct eq_ch *r)
{
	int i;

	for (i = 0; (r + i)->ch != '\0'; i++)
	{
		if (ch == (r + i)->ch)
			return (i);
	}
	return (-1);
}



/**
*my_signIndex - is the function that the index of the flag
*@ch: is the character we want to know its index
*@r: is the pointer to array of struct that we search in
*Return: index, or NULL for otherwise
*/


int my_signIndex(char ch, struct SIGNS *r)
{
	int i;

	for (i = 0; (r + i)->ch != '\0'; i++)
	{
		if (ch == (r + i)->ch)
			return (i);
	}
	return (-1);
}
