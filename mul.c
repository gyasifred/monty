#include "monty.h"

/**
 * mul - Multiplies the second top element of the stack
 * @stack: The head of the stack
 * @line_numb: The line on which the error occurred
 *
 * Return: Nothing
 */
void mul (stack_t **stack, unsigned int line_numb)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, len = 0;

	len = c_stack(*stack);

	if (len < 2)
		handle_error(ERR_MUL_USG, NULL, line_numb, NULL);

	a = temp->n;
	b = temp->next->n;
	temp->next->n = b * a;
	*stack = temp->next;
	free(temp);
}
