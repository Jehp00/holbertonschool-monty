#ifndef MONTY_H
#define MONTY_H

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

/*Global values*/

#define UNUSED(x) (void)(x)
#define TRUE 1
#define FALSE 0
#define DELIMITS "\n \t\r"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - globally useful variables
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction struct
 */

typedef struct global_s
{
	stack_t **top;
	instruction_t **ops;
} global_t;

extern global_t global;

/*prototypes*/
/*colaborator_functions.c*/

int file_proccessing(char *name, stack_t **stack);
void decide_op(stack_t **stack, char *op, unsigned int line_num);
int isdigt(char val);

/*Instructions.c*/

void instruction_push(stack_t **stack, unsigned int line_num);
void instruction_pall(stack_t **stack, unsigned int line_num);
void instruction_pint(stack_t **stack, unsigned int line_num);
void instruction_pop(stack_t **stack, unsigned int line_number);
void instruction_swap(stack_t **stack, unsigned int line_number);
void instruction_add(stack_t **stack, unsigned int line_number);
void instruction_nop(stack_t **stack, unsigned int line_number);
/*monty_man.c*/

void stack_int(stack_t **head);
void free_all(void);

/*anothers*/
int _strtol(char *num_str, unsigned int line_num);
#endif
