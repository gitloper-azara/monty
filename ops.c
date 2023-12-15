#include "monty.h"

/**
 * tokenise - a function that generates tokens
 * @line: line read from file
 * @line_number: line number from file
 * Return: token
*/

char **tokenise(char *line, unsigned int line_number)
{
	char **lineHolder = NULL;
	char *token, *delim = " \n\t";
	size_t i;
	(void)line_number;

	if (line != NULL && line[0] == '#')
		return (NULL);

	lineHolder = malloc(sizeof(char *) * MAX_TOKENS);
	if (lineHolder == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delim);
	i = 0;
	while (token != NULL)
	{
		lineHolder[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	lineHolder[i] = NULL;

	if (i == 0)
		return (NULL);

	return (lineHolder);
}

/**
 * is_number - a function that checks if a given str is a number of not
 * @str: string to chech
 * Return: bool true or false
 */

bool is_number(const char *str)
{
	size_t i;

	if (str == NULL || *str == '\0')
		return (false);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]) && (i == 0 && str[i] != '-'))
			return (false);
	}

	return (true);
}

/**
 * get_ops - a function that matches the opcode to struct opcodes
 * @ops: ops to check for
 * @stack: struct stack
 * @line_number: the line number
 * Return: pointer to the op function, or NULL
*/

void get_ops(char **ops, stack_t **stack, unsigned int line_number)
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
		{"rotl", op_rotl},
		{"rotr", op_rotr},
		{NULL, NULL}
	};
	unsigned int idx = 0;

	monty.opcode = ops[0];
	while (monty.opcode)
	{
		if ((_stack(monty.opcode)) || (_queue(monty.opcode)))
		{
			monty.dataStruct = _dataStruct(monty.opcode);
			return;
		}
		while (search_op[idx].opcode)
		{
			if (strcmp(search_op[idx].opcode, monty.opcode) == 0)
			{
				if (strcmp(monty.opcode, "push") == 0)
				{
					if (ops[1] == NULL || !is_number(ops[1]))
					{
						dprintf(STDERR_FILENO,
							"L%u: usage: push integer\n",
							line_number);
						exit(EXIT_FAILURE);
					}
					global_variable = atoi(ops[1]);
				}
				search_op[idx].f(stack, line_number);
				return;
			}
			idx++;
		}
		dprintf(STDERR_FILENO,
			"L%d: unknown instruction %s\n", line_number,
			monty.opcode);
		exit(EXIT_FAILURE);

		/* get the next token */
		/* monty.opcode = strtok(NULL, " \t"); */
	}
}
