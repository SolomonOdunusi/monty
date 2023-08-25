#include "monty.h"

/**
 * push - the func pushes an element to the stack
 * @stack: double pointer to head in stack
 * @line_number: line number
 * Return: returns void
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
