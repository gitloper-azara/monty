#include "monty.h"

/**
 * main - program entry point
 * @argc: argument count
 * @argv: argument vector array
 *
 * Return: EXIT_SUCCESS, or EXIT_FAILURE
*/

int main(int argc, char **argv)
{
	FILE *fp;
	ssize_t bytesREAD;
	size_t length = 0;
	char *line = NULL, *token = NULL;
	int lineNUM = 0;
	stack_t *head = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fp = fopen(argv[1], "r");
		if (fp == NULL)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			bytesREAD = getline(&line, &length, fp);
			while (bytesREAD != -1)
			{
				lineNUM++;
				token = tokenise(line, lineNUM);
				if (token)
					get_ops(token, &head, lineNUM);
			}
		}
		free(line);
		freeStack(head);
		fclose(fp);
	}

	return (EXIT_SUCCESS);
}
