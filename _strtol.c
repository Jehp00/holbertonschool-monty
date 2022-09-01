#include "monty.h"


int _strtol(char *num_str, unsigned int line_num)
{
	int base = 10;
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
		if (!isdigit(num_str[0]) && *endptr != '\0')
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
			/*printf("L%d: usage: push integer\n", line_num);*/
			exit(EXIT_FAILURE);
			
		}
	}
	return (value);
}
