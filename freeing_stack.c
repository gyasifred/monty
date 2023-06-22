#include "monty.h"

/**
  * check_free_stack - Releases all elements in the stack
  *
  * Return: Nothing
  */
void check_frees_stack(void)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;

		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}
