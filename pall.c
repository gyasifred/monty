#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: The head of the stack
 * @line_numb: The line on which the error occurred
 *
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_numb)
{
	stack_t *current = NULL;
	(void) line_numb;

	if (*stack)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}
