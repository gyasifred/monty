#include "monty.h"

/**
  * rotl - Rotates the stack to the top
  * @stack: The head of the stack
  * @err_loc: The line on which the error occurred
  *
  * Return: void
  */
void rotl(stack_t **stack, unsigned int err_loc)
{
	stack_t *current = *stack;
	unsigned int temp = 0;
	(void) err_loc;

	if (current && current->next)
	{
		while (current->next != NULL)
		{
			temp = current->n;
			current->n = current->next->n;
			current->next->n = temp;
			current = current->next;
		}
	}
}
