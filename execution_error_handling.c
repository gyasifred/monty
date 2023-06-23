#include "monty.h"

/**
  * handle_exec - the operations to be executed by the interpreter
  * @opcode: The operation code to be handled
  * @opparams: The parameter of the instruction
  * @line: The line on which the error occurred
  * @a: The approach to be used by the interpreter
  *
  * Return: 0 if the operation was executed correctly or errcode if is invalid
  */
int handle_execution(char *opcode, char *opparams, unsigned int line, int a)
{
	int opstatus = 0;
	void (*optr)(stack_t **, unsigned int);

	if (strcmp(opcode, "stack") == 0)
		return (METH_STACK);
	else if (strcmp(opcode, "queue") == 0)
		return (METH_QUEUE);

	optr = pick_func(opcode);
	if (optr)
	{
		if (strcmp(opcode, "push") == 0)
		{
			opstatus = check_push_params(opparams);
			if (opstatus == ERR_PUSH_USG)
				return (ERR_PUSH_USG);

			if (a != 0 && a == METH_QUEUE)
				optr = pick_func("push_queue");

			optr(&head, atoi(opparams));
		}
		else
		{
			optr(&head, line);
		}

		return (a);
	}

	return (ERR_BAD_INST);
}
