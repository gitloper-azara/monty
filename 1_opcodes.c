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

/**
 * op_sub - a function that subtracts the top element of the stack from the
 * second top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_div - a function that divides the second top element of the stack by the
 * top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_div(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	op_pop(stack, line_number);
}

/**
 * op_mul - a function that multiplies the second top element of the stack
 * with the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	op_pop(stack, line_number);
}

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
