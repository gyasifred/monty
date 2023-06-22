#include "monty.h"

/**
  * pchar - Prints the char at the top of the stack,
  * followed by a new line
  * @stack: The head of the stack
  * @lin_num: The line on which the error occurred
  *
  * Return: void
  */
void pchar(stack_t **stack, unsigned int lin_num)
{
	if (*stack == NULL)
		handle_error(ERR_PCH_EMP, NULL, lin_num, NULL);

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
		printf("%c\n", (*stack)->n);
	else
		handle_error(ERR_PCH_USG, NULL, lin_num, NULL);
}
