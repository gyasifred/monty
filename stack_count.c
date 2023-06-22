#include "monty.h"

/**
  * c_stack - Counts the number of elements in the stack
  * @stack: The stack to be counted
  *
  * Return: Number of elements in the stack
  */
unsigned int c_stack(stack_s *stack)
{
	stack_s *current = stack;
	unsigned int len = 0;

	while (current != NULL)
	{
		++len;
		current = current->next;
	}

	return (len);
}
