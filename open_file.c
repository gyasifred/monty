#include "monty.h"

/**
  * open_file - Opens a file to interpret the commands within
  * @filename: The file to be opened
  *
  * Return: The file descriptor of the opened file
  */
FILE *open_file(char *filename)
{
	FILE *file = NULL;

	check_access_file(filename);

	file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}
