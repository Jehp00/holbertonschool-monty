#include "monty.h"

global_t global;

void stack_int(stack_t **head)
{
	*head = NULL;
	global.top = head;
}

void free_all(void)
{
	stack_t *tmp_1, *tmp_2 = NULL;

	tmp_1 = *(global.top);
	while (tmp_1 != NULL)
	{
		tmp_2 = tmp_1->next;
		free(tmp_1);
		tmp_1 = tmp_2;
	}
}


int main(int argc, char **argv)
{
	stack_t *head;

	stack_int(&head);
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_proccessing(argv[1], &head);
	exit(EXIT_SUCCESS);
}
