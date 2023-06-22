#include "monty.h"

/**
 * pint - Prints the integer at the top of the stack followed by a new line.
 * @stack: The head of the stack
 * @err_loc: The line on which the error occurred
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int err_loc)
{
	if (*stack == NULL)
		handle_error(ERR_PINT_USG, NULL, err_loc, NULL);

	printf("%d\n", (*stack)->n);
}
