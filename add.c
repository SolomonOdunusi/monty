#include "monty.h"

/**
 * add - the func adds the top two elements in the stack
 * @stack: the stack
 * @line_number: the line number of opcode
 * Return: returns void
*/

void add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
