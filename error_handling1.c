#include "monty.h"

/**
  * handle_error - Handles the printing of interpreter errors
  * @errno: The error code to handle
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  * @buff: The reserved error line buffer
  *
  * Return: Void
  */
void handle_error(int errno, char *opcode, unsigned int line, char *buff)
{
	if (errno >= 100 && errno < 200)
		handle_err1(errno, opcode, line);
	else if (errno >= 200 && errno <= 210)
		handle_err2(errno, line);
	else if (errno >= 211 && errno <= 220)
		handle_err3(errno, line);
	else
		return;

	c_stack();

	if (buff)
		free(buff);

	exit(EXIT_FAILURE);
}

/**
  * handle_error - Manages common interpreter errors
  * @errno: The error code to manage
  * @opcode: The operation code to manage
  * @line: The line on which the error occurred
  *
  * Return: Nothing
  */
void handle_error(int errno, char *opcode, unsigned int line)
{
	switch (errno)
	{
		case ERR_BAD_INST:
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
			break;
		case ERR_BAD_MALL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}
