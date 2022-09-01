#include "monty.h"

void instruction_push(stack_t **stack, unsigned int line_num)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *op;
	int num;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	op = strtok(NULL, DELIMITS);
	if (op == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_num);
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

void instruction_pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: Can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

void instruction_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	node  = *stack;
	(*stack) = (*stack)->next;
	free(node);
}

void instruction_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	UNUSED(line_number);
	if (!(*stack) || !((*stack)->next))
	{
		printf("L%u: can't swap, stack too short\n", line_number);
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
