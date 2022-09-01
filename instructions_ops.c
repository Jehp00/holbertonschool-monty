#include "monty.h"

void instruction_push(stack_t **stack, unsigned int line_num)
{
	stack_t *element = malloc(sizeof(stack_t));
	char *tokenize;
	int num;

	if (element == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tokenize = strtok(NULL, DELIMITS);
	if (tokenize == NULL || stack == NULL)
	{
		printf("L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	num = _strtol(tokenize, line_num);
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
