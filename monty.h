#ifndef MONTY_H
#define MONTY_H

#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_TOKENS 100
#define USE_STACK 2
#define USE_QUEUE 1
#define USE_DEFAULT 0
/* macro definitions for stack, queue and dataStruct */
#define _stack(opcode) (strcmp((opcode), "stack") == 0)
#define _queue(opcode) (strcmp((opcode), "queue") == 0)
#define _dataStruct(opcode) ((_stack(opcode)) ? USE_STACK : ((_queue(opcode)) ? USE_QUEUE : USE_DEFAULT))

extern int global_variable;

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
 * struct monty_s - keep track of stacks and queues
 * @dataStruct: data structure to use
 * @size: size of stack and queue tracker
 * @tail: helps to use Queue dataStruct
 */

typedef struct monty_s
{
	int dataStruct; /* USE_STACK or USE_QUEUE or USE_DEFAULT */
	size_t size;
	char *opcode;
	stack_t *tail; /* used if dataStruct == USE_QUEUE */
} monty_s;

/* declare monty globally */
extern monty_s monty;

/* op_codes */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
void op_pint(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **stack, unsigned int line_number);
void op_swap(stack_t **stack, unsigned int line_number);

/* arithmetic ops */
void op_add(stack_t **stack, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_sub(stack_t **stack, unsigned int line_number);
void op_div(stack_t **stack, unsigned int line_number);
void op_mul(stack_t **stack, unsigned int line_number);
void op_mod(stack_t **stack, unsigned int line_number);

/* str ops */
void op_pchar(stack_t **stack, unsigned int line_number);
void op_pstr(stack_t **stack, unsigned int line_number);

/* rotl and rotr ops */
void op_rotl(stack_t **stack, unsigned int line_number);
void op_rotr(stack_t **stack, unsigned int line_number);

/* ops handlers */
char *tokenise(char *line, unsigned int line_number);
void get_ops(char *ops, stack_t **stack, unsigned int line_number);

/* memory */
void *_calloc(unsigned int nmemb, unsigned int size);
void freeStack(stack_t *head);

#endif /* MONTY_H */
