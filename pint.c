#include "monty.h"

/**
 * pint - the func prints the data at the top of stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number
 * Return: returns void
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
