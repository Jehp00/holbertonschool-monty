#include "monty.h"


int file_proccessing(char *name, stack_t **stack)
{
	size_t lenght;
	ssize_t read;
	unsigned int line_num = 0;
	char *line = NULL;
	FILE *fp;
	char *op;

	if (!name)
	{
		printf("Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	fp = fopen(name, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while ((read = getline(&line, &lenght, fp)) != -1)
	{
		op = strtok(line, DELIMITS);
		line_num++;
		if (op)
		{
			decide_op(stack, op, line_num);
		}
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}


void decide_op(stack_t **stack, char *op, unsigned int line_num)
{
	int a = 0;
	instruction_t all_ops[] = {
		{"push", instruction_push},
		{"pall", instruction_pall},
		{"pint", instruction_pint},
		{NULL, NULL}
	};
	for (a = 0; all_ops[a].opcode; a++)
	{
		if (strcmp(op, all_ops[a].opcode) == 0)
		{
			all_ops[a].f(stack, line_num);
			return;
		}
	}
	if (strlen(op) != 0 && op[0] != '#')
	{
		printf("L%u: unknown instruction %s\n", line_num, op);
		exit(EXIT_FAILURE);
	}
}
