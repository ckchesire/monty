#include "monty.h"

/**
 * pop - function removes top element from stack
 * @stack: the pointer to the stack
 * @line_number: line number where pop is retrieved
 * Return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (global_args->head == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	remove_stack_node();
	global_args->stack_length -= 1;
}

/**
 * remove_stack_node - function deletes node at the top of stack
 * Return: nothing
 */
void remove_stack_node(void)
{
	stack_t *temp;

	temp = global_args->head;
	global_args->head = temp->next;
	free(temp);
}

/**
 * swap - function that swaps the top 2 elements in stack
 * @stack: pointer to stack
 * @line_number: line number where pop is retrieved
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void) stack;
	(void) line_number;
	if (global_args->stack_length < 2)
	{
		dprintf(2, "L%d: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp1 = global_args->head;
	temp2 = temp1->next;
	temp1->next = temp2->next;
	if (temp1->next)
		temp1->next->prev = temp1;
	temp2->next = temp1;
	temp1->prev = temp2;
	temp2->prev = NULL;
	global_args->head = temp2;
}

/**
 * add - function adds the top a 2 elements of the stack
 * @stack: refers to the pointer to the stack
 * @line_number: line no. where the add function is called
 * Return: returns nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;

	if (global_args->stack_length < 2)
	{
		dprintf(2, "L%d: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->head;
	temp2 = temp1->next;

	temp2->n = temp1->n + temp2->n;
	remove_stack_node();

	global_args->stack_length -= 1;
}

/**
 * nop - function does not do anything
 * @stack: refers to the pointer to the stack
 * @line_number: line no. where the add function is called
 * Return: returns nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	free_all();
	exit(0);
}
