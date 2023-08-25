#include "monty.h"
#include <stdio.h>

void betty(void);
stack_t *stack = NULL;

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: returns 0 on success else 1
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int result;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		result = op_func(line, &stack, line_number, file);
		if (result == 1)
		{
			fprintf(stderr, "Error executing line %u: %s\n", line_number, line);
			fclose(file);
			free(line);
			free_s(stack);
			return (EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
	if (line)
	{
		free(line);
	}
	free_s(stack);
	return (EXIT_SUCCESS);
}
