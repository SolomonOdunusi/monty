#include "monty.h"

/**
 * op_func - function that selects the correct function
 * @content: the content
 * @stack: stack
 * @line_num: the line number
 * @file: file
 * Return: returns 0 on success else 1
*/
int op_func(char *content, stack_t **stack, unsigned int line_num, FILE *file)
{
	instruction_t op_codes[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, DELIM);
	if (op && op[0] == '#')
		return (0);

	while (op_codes[i].opcode && op)
	{
		if (strcmp(op, op_codes[i].opcode) == 0)
		{
			op_codes[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if (op && op_codes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		fclose(file);
		free(content);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
