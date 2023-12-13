#include "monty.h"
#include <stdio.h>

/**
 * tokenise - a function that generates tokens
 * @line: line read from file
 * @line_number: line number from file
 * Return: token
*/

char **tokenise(char *line, unsigned int line_number)
{
    char **tokens;
    char *token;
    char delim[2] = "\n ";
    int i;

    tokens = malloc(MAX_TOKENS * sizeof(char *));
    if (!tokens)
    {
        fprintf(stderr, "Error: Unable to allocate memory for tokens"
        " at line %u\n", line_number);
        exit(EXIT_FAILURE);
    }

    token = strtok(line, delim);
    i = 0;
    while (token)
    {
        tokens[i++] = strdup(token);
        if (!token[i - 1])
        {
            fprintf(stderr, "Error: Unable to allocate memory for tokens"
        " at line %u\n", line_number);
        exit(EXIT_FAILURE);
        }
        token = strtok(NULL, delim);
    }

    tokens[i] = NULL;
    return (tokens);
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
        {NULL, NULL}
    };
    int idx = 0;

    while (search_op[idx].opcode)
    {
        if (strcmp(search_op[idx].opcode, *ops) == 0)
        {
            search_op[idx].f(stack, line_number);
            return;
        }
        idx++;
    }
    printf("L%d: Unknown instruction %s\n", line_number, *ops);
    exit(EXIT_FAILURE);
}