#include "monty.h"

/**
 * pop - the func removes the top element of the stack
 * @stack: a double pointer to head stack
 * @line_number: the line number of opcode
 * Return: returns void
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = (*stack);

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack) = (*stack)->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(current);
	}
}
