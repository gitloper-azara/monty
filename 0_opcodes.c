#include "monty.h"
int global_variable;

/**
 * op_push - a function that implements the push opcodes that
 * pushes an element to the stack
 * @stack: struct stack
 * @line_number: line number
*/

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	(void)line_number;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = global_variable;
	newNode->prev = NULL;

	if (!(*stack))
	{
		newNode->next = NULL;
		*stack = newNode;
		return;
	}
	newNode->next = *stack;
	(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * op_pall - a function that implements the pall opcodes that
 * prints all the values on the stack from the top of the stack
 * @stack: struct stack
 * @line_number: line number
*/

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	if (!(*stack))
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
