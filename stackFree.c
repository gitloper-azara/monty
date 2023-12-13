#include "monty.h"

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