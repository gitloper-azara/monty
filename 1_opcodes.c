#include "monty.h"

/**
 * op_add - a function that adds the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_nop - does not do anything
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
