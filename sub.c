#include "monty.h"

/**
 * sub - the func subtracts the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 * Return: returns void
*/

void sub(stack_t **stack, unsigned int line_number)
{
	int result;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = result;
}
