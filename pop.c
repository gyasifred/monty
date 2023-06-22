#include "monty.h"

/**
 * pop - Removes the top item of the stack
 * @stack: The head of the stack
 * @err_loc: The line on which the error occurred
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int err_loc)
{
	stack_t *current = *stack, *temp = NULL;

	if (*stack == NULL)
		handle_error(ERR_POP_USG, NULL, err_loc, NULL);

	temp = current;
	if (current->next)
	{
		current = current->next;
		current->prev = temp->prev;
		*stack = current;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}
