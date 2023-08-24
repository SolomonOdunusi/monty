#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
stack_t *stack = NULL;

int main(int argc, char *argv[]) {
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		char *opcode, *arg;
		opcode = strtok(line, " \t\n");
		if (opcode && strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg)
			{
				int value = atoi(arg);
				push(&stack, line_number);
			}
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				fclose(file);
				if (line)
				{
					free(line);
				}
				return EXIT_FAILURE;
			}
		}
		else if (opcode && strcmp(opcode, "pall") == 0)
		{
			pall(&stack, line_number);
		}
		line_number++;
	}
	fclose(file);
	if (line)
	{
		free(line);
	}
	return EXIT_SUCCESS;
}
