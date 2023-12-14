#include "monty.h"

/**
 * tokenise - a function that generates tokens
 * @line: line read from file
 * @line_number: line number from file
 * Return: token
*/

char *tokenise(char *line, unsigned int line_number)
{
	char *lineHolder = NULL;
	char *token, *delim = " \n";
	size_t i;

	if (line != NULL && line[0] == '#')
		return (NULL);

	token = strtok(line, delim);
	if (token == NULL)
		return (NULL);

	lineHolder = strtok(NULL, delim);
	if (lineHolder)
	{
		for (i = 0; i < strlen(lineHolder); i++)
		{
			if (!isdigit(lineHolder[i]))
			{
				dprintf(STDERR_FILENO,
					"L%u: usage: push integer\n",
					line_number);
				exit(EXIT_FAILURE);
			}
		}
		global_variable = atoi(lineHolder);
	}
	else if (lineHolder == NULL && strcmp(token, "push") == 0)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	return (token);
}

/**
 * get_ops - a function that matches the opcode to struct opcodes
 * @ops: ops to check for
 * @stack: struct stack
 * @line_number: the line number
 * Return: pointer to the op function, or NULL
*/

void get_ops(char *ops, stack_t **stack, unsigned int line_number)
{
	instruction_t search_op[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{NULL, NULL}
	};
	unsigned int idx = 0;

	while (search_op[idx].opcode)
	{
		if (strcmp(search_op[idx].opcode, ops) == 0)
		{
			search_op[idx].f(stack, line_number);
			return;
		}
		idx++;
	}

	dprintf(STDERR_FILENO,
		"L%d: Unknown instruction %s\n", line_number, ops);
	exit(EXIT_FAILURE);
}
