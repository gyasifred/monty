#include "monty.h"

/**
  * check_args_numbs - Checks num of arguments passed on to the interpreter
  * @argc: Number of arguments
  *
  * Return: Nothing
  */
void check_args_numbs(int argc)
{
	if (argc != MIN_ARGS)
		handle_err(ERR_ARG_USG, NULL, 0, NULL);
}

/**
  * check_access_file - Checks if the user has permissions to read the file
  * @fname: The pathname of the file
  *
  * Return: Nothing
  */
void check_access_file(char *fname)
{
	if (access(fname, R_OK) == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
}

/**
  * check_push_params - Check the parameter of the push instruction
  * @params: The params to be verified
  *
  * Return: 0 if is a valid data or errcode if is invalid
  */
int check_push_params(char *params)
{
	if (params == NULL || check_digits(params) == 0)
		return (ERR_PUSH_USG);

	return (VALID_PARM);
}

/**
  * check_digit - Checks if all passed characters are digits
  * @str: The string to be evaluated
  *
  * Return: 1 if all if all evaluated characters are digits or 0 if not
  */
int check_digit(char *str)
{
	int status = 1;

	while (*str != '\0')
	{
		if (str[0] == 45)
		{
			++str;
			continue;
		}

		if (isdigit(*str) == 0)
		{
			status = 0;
			return (status);
		}

		++str;
	}

	return (status);
}
