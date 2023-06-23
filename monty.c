#define _GNU_SOURCE
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
	unsigned int line_num = 1;
	int nch_read = 0, op_status = 0;
	char *filename = NULL, *op_code = NULL, *op_param = NULL, *buff = NULL;

	filename = argv[1];
	check_args_numbs(argc);
	file = open_file(filename);

	while ((nch_read= getline(&buff, &line_length, file)) != -1)
	{
		op_code = strtok(buff, "\t\n ");
		if (op_code)
		{
			if (op_code[0] == '#')
			{
				++line_num;
				continue;
			}

			op_param = strtok(NULL, "\t\n ");
			op_status = handle_execution(op_code, op_param, line_num, op_status);

			if (op_status >= 100 && op_status < 300)
			{
				fclose(file);
				handle_error(op_status, op_code, line_num, buff);
			}
		}

		++line_num;
	}

	frees_stack();
	free(buff);
	fclose(file);
	return (0);
}