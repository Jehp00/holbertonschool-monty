#include "monty.h"

global_t global;

/**
 * stack_int - initialize all the things
 * @head: top of stack data structure
 **/

void stack_int(stack_t **head)
{
	*head = NULL;
	global.top = head;
}

/**
 * free_all - frees all malloc memory
 */

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

/**
 * main - monty byte-code interpreter
 * @argc: number of command line arguments
 * @argv: aray of strings containing the command line args
 * Return: EXIT_SUCCES or EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	stack_t *head;

	stack_int(&head);
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		/*printf("USAGE: monty file\n");*/
		exit(EXIT_FAILURE);
	}
	file_proccessing(argv[1], &head);
	exit(EXIT_SUCCESS);
}
