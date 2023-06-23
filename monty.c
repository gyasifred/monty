#include "monty.h"

stack_t *head = NULL;

/**
  * main - The Monty Interpreter entry point
  * @argc: The args number
  * @argv: The args passed to the interpreter
  *
  * Return: Always zero
  */
int main(int argc, char *argv[])
{
	FILE *file = NULL;
	size_t line_length = 0;
	unsigned int line_number = 1;
	int read = 0, status_op = 0;
	char *filename = NULL, *opcode = NULL, *opparams = NULL, *buff = NULL;

	filename = argv[1];
	check_args_numbs(argc);
	file = open_file(filename);

	while ((read = getline(&buff, &line_length, file)) != -1)
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
			status_op = handle_execution(opcode, opparams, line_number, status_op);

			if (status_op >= 100 && status_op < 300)
			{
				fclose(file);
				handle_error(status_op, opcode, line_number, buff);
			}
		}

		++line_number;
	}

	frees_stack();
	free(buff);
	fclose(file);
	return (0);
}
