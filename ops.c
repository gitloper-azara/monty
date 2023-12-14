#include "monty.h"

/**
 * tokenise - a function that generates tokens
 * @line: line read from file
 * @line_number: line number from file
 * Return: token
*/

char *tokenise(char *line, unsigned int line_number)
{
	char *line_copy = NULL;
	char *token, *result;
	char *delim = " \n";

	if (line != NULL)
	{
		line_copy = malloc(strlen(line) + 1);
		if (line_copy == NULL)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(line_copy, line);
	}
	token = strtok((line != NULL) ? line_copy : NULL, delim);
	if (token == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: Unknown instruction\n",
			line_number);
		exit(EXIT_FAILURE);
	}

	if (line != NULL && token != NULL)
	{
		result = strdup(token);
		if (result == NULL)
		{
			dprintf(STDERR_FILENO, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}
		free(line_copy);
	}
	else
		result = NULL;
	return (result);
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
		{NULL, NULL}
	};
	char *token = NULL;
	int idx = 0;

	while (search_op[idx].opcode)
	{
		if (strcmp(search_op[idx].opcode, ops) == 0)
		{
			if (strcmp(ops, "push") == 0)
			{
				token = tokenise(NULL, line_number);
				global_variable = atoi(token);
			}
			search_op[idx].f(stack, line_number);
			if (token)
			{
				free(token);
			}
			return;
		}
		idx++;
	}

	dprintf(STDERR_FILENO,
		"L%d: Unknown instruction %s\n", line_number, ops);
	if (token)
	{
		free(token);
	}
	exit(EXIT_FAILURE);
}
