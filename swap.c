#include "monty.h"

/**
 * swap - the func swaps the top two elements in the stack
 * @stack: the stack
 * @line_number: the line number of opcode
 * Return: returns void
*/

void swap(stack_t **stack, unsigned int line_number)
{
	int current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		current = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = current;
	}
}
