#include "monty.h"

/**
 * free_s - function that frees the stack
 * @stack: stack
 * Return: void
*/

void free_s(stack_t *stack)
{
	stack_t *current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
