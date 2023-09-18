#include "main.h"



/**
 * spIndex - Function to find the index of a special character in an array of structures.
 * @ch: The character to find the index of.
 * @p: Pointer to an array of 'struct sp_char' to search in.
 * Return: The index of the character, or -1 if not found.
 */

/*Function spIndex*/
int spIndex(char ch, struct sp_char *p)
{
	int i;

	/* Iterate through the array of structures until the end is reached */
	for (i = 0; (p + i)->ch != '\0'; i++)
	{
		/* Check if the current character matches the target character */
		if (ch == (p + i)->ch)
			return (i); /* Return the index of the character if found */
	}

	return (-1); /* Return -1 if the character is not found in the array */
}




/**
 * signIndex - Function to find the index of a flag character in an array of structures.
 * @ch: The flag character to find the index of.
 * @p: Pointer to an array of 'struct signs' to search in.
 * Return: The index of the flag character, or -1 if not found.
 */


/*Function signIndex*/
int signIndex(char ch, struct signs *p)
{
	int i;

	/* Iterate through the array of structures until the end is reached */
	for (i = 0; (p + i)->ch != '\0'; i++)
	{
		/* Check if the current character matches the target flag character */
		if (ch == (p + i)->ch)
			return (i); /* Return the index of the flag character if found */
	}

	return (-1); /* Return -1 if the flag character is not found in the array */
}
