#include "monty.h"

/**
 * mod_t - Computes the rest of the division of the second top element
 * @stack: The head of the stack
 * @line_numb: The line on which the error occurred
 *
 * Return: Nothing
 */
void mod_t(stack_t **stack, unsigned int line_numb)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, len = 0;

	len = count_stack(*stack);

	if (len < 2)
		handle_err(ERR_MOD_USG, NULL, line_numb, NULL);

	a = temp->u;

	if (a == 0)
		handle_err(ERR_DIV_ZRO, NULL, line_numb, NULL);

	b = temp->next->u;
	temp->next->u = b % a;
	*stack = temp->next;
	free(temp);
}