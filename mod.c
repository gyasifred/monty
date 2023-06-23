#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 * @stack: The head of the stack
 * @line_numb: The line on which the error occurred
 *
 * Return: Nothing
 */
void mod(stack_t **stack, unsigned int line_numb)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, len = 0;

	len = c_stack(*stack);

	if (len < 2)
		handle_error(ERR_MOD_USG, NULL, line_numb, NULL);

	a = temp->n;

	if (a == 0)
		handle_error(ERR_DIV_ZRO, NULL, line_numb, NULL);

	b = temp->next->n;
	temp->next->n = b % a;
	*stack = temp->next;
	free(temp);
}
