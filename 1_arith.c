#include "monty.h"

/**
 * op_mod - a function that computes the rest of the division of the second top
 * element of the stack with the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	op_pop(stack, line_number);
}
