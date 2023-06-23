#include "monty.h"

/**
 * sub - Subtracts the top element of the stack from
 *the second top element of the stack
 * @stack: The head of the stack
 * @err_loc: The line on which the error occurred
 * Return: void
 */
void sub(stack_t **stack, unsigned int err_loc)
{
	stack_t *temp = *stack;
	unsigned int i = 0, j = 0, len = 0;

	len = c_stack(*stack);

	if (len < 2)
		handle_error(ERR_SUB_USG, NULL, err_loc, NULL);

	i = temp->n;
	j = temp->next->n;
	temp->next->n = j - i;
	*stack = temp->next;
	free(temp);
}
