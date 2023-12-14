#include "monty.h"


/**
 * tokenise - a function that generates tokens
 * @line: line read from file
 * @line_number: line number from file
 * Return: token
*/

char *tokenise(char *line, unsigned int line_number)
{
	static char *line_copy = NULL;
	/* char *tokens; */
	char *token, *result;
	char *delim = " \n";

	if (line != NULL)
	{
		free(line_copy);
		line_copy = strdup(line);
		if (line_copy == NULL)
		{
			dprintf(STDERR_FILENO, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(line_copy, delim);
		if (token == NULL)
		{
			dprintf(STDERR_FILENO,
				"L%u: usage debug: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		result = strdup(token);
		free(line_copy);
		return (result);
	}
	else
	{
		token = strtok(NULL, delim);
		if (token == NULL)
		{
			dprintf(STDERR_FILENO,
				"L%u: usage debug1: push integer\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		result = strdup(token);
		if (result == NULL)
		{
			dprintf(STDERR_FILENO, "Error: strdup failed\n");
			exit(EXIT_FAILURE);
		}
		return (result);
	}
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
	char *token;
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
			free(token);
			return;
		}
		idx++;
	}

	dprintf(STDERR_FILENO,
		"L%d: Unknown instruction %s\n", line_number, ops);
	/* free(token); */
	exit(EXIT_FAILURE);
}
