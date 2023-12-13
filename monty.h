#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define MAX_TOKENS 100
#define MAX_LENGTH 100

extern char global_variable[];
char global_variable[MAX_LENGTH];
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

void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);
char **tokenise(char *line, unsigned int line_number);
void get_ops(char **ops, stack_t **stack, unsigned int line_number);
void freeStack(stack_t *head);

#endif /* MONTY_H */