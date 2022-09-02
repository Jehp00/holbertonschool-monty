#include "monty.h"

/**
 * instruction_add - adds the top two elements of the stack
 * @stack: stack where we want to operate
 * @line_number: line where we find the instruction
 *
 */

void instruction_add(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		/*printf("L%u: can't add, stack too short\n", line_number);*/
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	instruction_pop(stack, line_number);
	(*stack)->n += tmp;
}

/**
 * instruction_nop - It does not do anything
 * @stack: stack where we want to operate
 * @line_number: line where we find the instruction
 *
 */
void instruction_nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}

