#include "monty.h"

/**
*void Fuction fr_myqueue
*/
void fr_myqueue(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 1;
}

/**
*Void function that adds to queue
*/
void addtoqueue(stack_t **head, int x)
{
	stack_t *new_node, *temp;

	temp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->x = x;
	new_node->next = NULL;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
	}
	if (!temp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/**
*void functipn that removes from stsck like pop
*/
void freethe_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
* Void function that feel stack
*/
void ff_stack(stack_t **head, unsigned int count)
{
	(void)head;
	(void)count;
	bus.lifi = 0;
}
