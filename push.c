#include "monty.h"

/**
  * push - Adds a new node at the beginning of the stack
  * @stack: The head of the stack
  * @data: The integer to adds on the stack
  *
  * Return: void
  */
void push(stack_t **stack, unsigned int data)
{
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	newNode->n = data;
	if (*stack)
	{
		newNode->next = *stack;
		newNode->prev = (*stack)->prev;
		(*stack)->prev = newNode;
		*stack = newNode;
		return;
	}

	newNode->next = *stack;
	newNode->prev = NULL;
	*stack = newNode;
}

/**
  * push_queue - Adds a new node at the end of the stack
  * @stack: The head of the stack
  * @data: The integer to adds on the stack
  *
  * Return: void
  */
void push_queue(stack_t **stack, unsigned int data)
{
	stack_t *current = NULL, *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);

	newNode->n = data;
	if (*stack)
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;

		newNode->next = NULL;
		newNode->prev = current;
		current->next = newNode;
		return;
	}

	newNode->next = *stack;
	newNode->prev = NULL;
	*stack = newNode;
}
