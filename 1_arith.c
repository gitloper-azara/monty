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

/**
 * op_pchar - a function that prints the char at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_pchar(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	putchar(ascii);
	putchar('\n');
}

/**
 * op_pstr - a function that prints the string starting at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

        while (temp != NULL && temp->n != 0 && (temp->n >= 0 && temp->n <= 127))
	{
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
