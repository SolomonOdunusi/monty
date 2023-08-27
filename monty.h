#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define LEN 100
#define DELIM " \n\t"

/**
 * struct stack_s - struct doubly linked list of a stack and queue
 * @n: integer
 * @prev: points to the previous element of the stack or queue
 * @next: points to the next element of the stack or queue
 * Description: doubly linked list node struct for stack and queue
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
extern stack_t *stack;
/**
 * struct instruction_s - struct instruction for opcode
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: operation code and the functions
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void fr_myqueue(stack_t **head, unsigned int count)
void freethe_stack(stack_t *head)
void ff_stack(stack_t **head, unsigned int count)
void addtoqueue(stack_t **head, int x)
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
int op_func(char *content, stack_t **stack, unsigned int line_count, FILE *file);
void free_s(stack_t *stack);
void sub(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
