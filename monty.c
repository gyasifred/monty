#include "monty.h"

stack_t *head = NULL;

/**
  * main - The Monty Interpreter entry point
  * @argu: The args number
  * @arg: The args passed to the interpreter
  *
  * Return: Always zero
  */
int main(int argu, char *arg[])
{
	FILE *fd = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;
	int read = 0, status_op = 0;
	char *filename = NULL, *opcode = NULL, *opparams = NULL, *buff = NULL;

	filename = arg[1];
	check_arg_numb(argu);
	fd = open_file(filename);

	while ((read = getline(&buff, &line_length, fd)) != -1)
	{
		opcode = strtok(buff, "\t\n ");
		if (opcode)
		{
			if (opcode[0] == '#')
			{
				++line_number;
				continue;
			}

			opparams = strtok(NULL, "\t\n ");
			status_op = handle_exec(opcode, opparams, line_number, status_op);

			if (status_op >= 100 && status_op < 300)
			{
				f_close(fd);
				handle_err(status_op, opcode, line_number, buff);
			}
		}

		++line_number;
	}

	frees_stack();
	free(buff);
	f_close(fd);
	return (0);
}
