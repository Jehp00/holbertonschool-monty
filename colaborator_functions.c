#include "monty.h"

/**
 * file_proccessing - proccess the whole monty file
 * @name: str name of monty opcode file
 * @stack: double pointer to top of stack data strct
 * Return: return an error or succes
 */

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
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", name);
		/*printf("Error: Can't open file %s\n", name);*/
		exit(EXIT_FAILURE);
	}
	fp = fopen(name, "r");
	if (fp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", name);
		/*printf("Error: Can't open file %s\n", name);*/
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

/**
 * decide_op - based on tokens from single line, decide what function to call
 * @stack: double pointer to head of stack data structure
 * @op: operator, token[0] from getline
 * @line_num: line in vyte-code file being proccessed, zero indexed
 * Return: int for mysterious purposes
 */

void decide_op(stack_t **stack, char *op, unsigned int line_num)
{
	int a = 0;
	instruction_t all_ops[] = {
		{"push", instruction_push},
		{"pall", instruction_pall},
		{"pint", instruction_pint},
		{"pop", instruction_pop},
		{"swap", instruction_swap},
		{"add", instruction_add},
		{"nop", instruction_nop},
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
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_num, op);
		/*printf("L%u: unknown instruction %s\n", line_num, op);*/
		exit(EXIT_FAILURE);
	}
}
