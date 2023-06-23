#include "monty.h"

/**
 * add_t - Adds the top two elements of the stack
 * @stack: The head of the stack
 * @line_numb: The line on which the error occurred
 *
 * Return: Nothing
 */
void add_t(stack_t **stack, unsigned int line_numb)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, len = 0;

	len = count_stack(*stack);

	if (len < 2)
		handle_err(ERR_ADD_USG, NULL, line_number, NULL);

	a = temp->u;
	b = temp->next->u;
	temp->next->u = a + b;
	*stack = temp->next;
	free(temp);
}
