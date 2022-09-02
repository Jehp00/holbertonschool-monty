#include "monty.h"

/**
 * 
 * 
 * 
 * 
 */

/*int isdigt(char val)
{
	int j;

	for (j = 0; val[j] != '\0'; j++)
	{
		if (val[j] <= 57 && val[j] >= 48)
		{
			continue;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}*/

int isdigt(char val)
{
	if (val <= 57 && val >= 48)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}		