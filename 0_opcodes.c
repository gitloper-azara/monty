#include "monty.h"
int global_variable;

/**
 * op_push - a function that implements the push opcodes that
 * pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
*/

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode = NULL;
	(void)line_number;

	/* allocate memory for new node */
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* set node values */
	newNode->n = global_variable;
	newNode->prev = NULL;

	/* check for empty stack */
	if (!(*stack))
	{
		newNode->next = NULL;
		*stack = newNode;
	}
	else
	{
		if (monty.dataStruct == USE_QUEUE)
		{
			monty.tail->next = newNode;
			newNode->prev = monty.tail;
			monty.tail = newNode;
		}
		else
		{
			newNode->next = *stack;
			(*stack)->prev = newNode;
			if ((*stack)->next == NULL)
				(*stack)->prev = newNode;
			*stack = newNode;
		}
	}
	/* reset global variable to 0 */
	monty.size++;
}

/**
 * op_pall - a function that implements the pall opcodes that
 * prints all the values on the stack from the top of the stack
 * @stack: double pointer to the head of the stack
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

/**
 * op_pint - a function that prints the value at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of monty file
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	temp = *stack;
	printf("%d\n", temp->n);

	if (!stack || !(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't print, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * op_pop - a function that removes the top element of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the monty file
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * op_swap - a function that swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of monty file
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	(*stack)->next = temp->next;
	temp->prev = NULL;

	if (temp->next)
		temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;

	*stack = temp;
}
