#include "monty.h"

/**
 * 
 * 
 * 
 * 
 */

int isdigt(char *val)
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
			return (1);
		}
	}
	return (0);
}