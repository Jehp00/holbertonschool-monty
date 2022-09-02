#include "monty.h"

/**
 * isdigt - this function verifies if digit
 * @val: character to value
 * Return: 0 if not digit
 *
 */

int isdigt(char val)
{
	if (val <= 57 && val >= 48)
	{
		return (1);
	}
	return (0);
}
