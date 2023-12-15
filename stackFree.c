#include "monty.h"

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: element size
 * @size: size of bytes to allocate
 * Return: pointer to the array
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	void *array;
	char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = array = malloc(nmemb * size);
	if (array == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < nmemb * size; i++)
		s[i] = 0;

	return (array);
}

/**
 * free_token - frees memory used by tokens
 * @token: token
 * @num_tokens: number of tokens
 */

void free_token(char **token, size_t num_tokens)
{
	size_t i;

	for (i = 0; i < num_tokens; ++i)
		free(token[i]);
	free(token);
}

/**
 * freeStack - a function that frees a stack
 * @head: head pointer of the stack
 * Return: void
*/

void freeStack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
