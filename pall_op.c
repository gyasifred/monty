#include "monty.h"

/**
 * pall_op - Prints all the values on the stack
 * @stack: The head of the stack
 * @line_numb: The line on which the error occurred
 *
 * Return: Nothing
 */
void pall_op(stack_t **stack, unsigned int line_numb)
{
	stack_t *current = NULL;
	(void) line_numb;

	if (*stack)
	{
		current = *stack;
		while (current != NULL)
		{
			printf("%d\n", current->u);
			current = current->next;
		}
	}
}
