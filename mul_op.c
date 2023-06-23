#include "monty.h"

/**
 * mul_op - Multiplies the second top element of the stack
 * @stack: The head of the stack
 * @line_numb: The line on which the error occurred
 *
 * Return: Nothing
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	unsigned int a = 0, b = 0, len = 0;

	len = count_stack(*stack);

	if (len < 2)
		handle_err(ERR_MUL_USG, NULL, line_numb, NULL);

	a = temp->u;
	b = temp->next->u;
	temp->next->u = b * a;
	*stack = temp->next;
	free(temp);
}
