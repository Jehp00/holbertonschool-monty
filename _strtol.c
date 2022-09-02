#include "monty.h"

/**
 * _strtol - converts a character string to a long int value
 * @num_str: string to covert
 * @line_num: line number in the file where we find the function
 * Return: integer value
 */
int _strtol(char *num_str, unsigned int line_num)
{
	int base = 10, j;
	char *endptr;
	long value;

	errno = 0;
	value = strtol(num_str, &endptr, base);

	if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN)) ||
			(errno != 0 && value == 0))
	{
		exit(EXIT_FAILURE);
	}
	if (endptr == num_str)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
		/*printf("L%d: usage: push integer\n", line_num);*/
		exit(EXIT_FAILURE);
	}
	if (num_str[0] != '\0')
	{
		for (j = 0; num_str[j] != '\0'; j++)
		{
			if (!isdigt(num_str[j]) && *endptr != '\0')
			{
				dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
				/*printf("L%d: usage: push integer\n", line_num);*/
				exit(EXIT_FAILURE);
			}
			else
			{
				continue;
			}
		}
	}
	return (value);
}
