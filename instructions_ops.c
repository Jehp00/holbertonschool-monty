#include "monty.h"

/**
 * instruction_push - push stack function
 * @stack: stack where we want to push
 * @line_num: line to push
 *
 */

void instruction_push(stack_t **stack, unsigned int line_num)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *op;
	int num;

	if (element == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		/*printf("Error: malloc failed\n");*/
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMITS);
	if (op == NULL || stack == NULL || isdigt(op) != 0)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_num);
		/*printf("L%u: usage: push integer\n", line_num);*/
		exit(EXIT_FAILURE);
	}
	num = _strtol(op, line_num);
	element->n = num;
	element->prev = NULL;
	element->next = *stack;
	if (element->next != NULL)
	{
		(element->next)->prev = element;
	}
	*stack = element;
}

/**
 * instruction_pall - print all elements in stack
 * @stack: stack to print
 * @line_num: unused variable
 *
 */

void instruction_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *element = *stack;

	UNUSED(line_num);
	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}

/**
 * instruction_pint - prints the value at the top of the stack
 * @stack: stack where we want to operate
 * @line_num: line where we find the instruction
 *
 */
void instruction_pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_num);
		/*printf("L%u: Can't pint, stack empty\n", line_num);*/
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * instruction_pop - removes the top of the stack
 * @stack: stack where we want to operate
 * @line_number: line where we find the instruction
 *
 */

void instruction_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		/*printf("L%u: can't pop an empty stack\n", line_number);*/
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}

/**
 * instruction_swap - removes the top of the stack
 * @stack: stack where we want to operate
 * @line_number: line where we find the instruction
 *
 */

void instruction_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	if (!(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		/*printf("L%u: can't swap, stack too short\n", line_number);*/
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack) = (*stack)->prev;
}
