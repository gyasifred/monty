#include "monty.h"

/**
  * pstr - Prints the string starting at the top of the stack, followed by a new line
  * @stack: The head of the stack
  * @err_loc: The line on which the error occurred
  * Return: void
  */
void pstr(stack_t **stack, unsigned int err_loc)
{
	stack_t *current = *stack;
	(void) err_loc;

	while (current != NULL)
	{
		if (current->n == 0 || current->n < 0 || current->n > 127)
			break;

		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
