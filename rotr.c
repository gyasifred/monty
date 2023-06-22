#include "monty.h"

/**
  * rotr - Rotates the stack to the bottom
  * @stack: The head of the stack
  * @err_loc: The line on which the error occurred
  *
  * Return: void
  */
void rotr(stack_t **stack, unsigned int err_loc)
{
	stack_t *last = NULL;
	(void) err_loc;

	if (*stack && (*stack)->next)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->prev->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}
