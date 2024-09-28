#include "monty.h"
/**
 * sub - function subtracts the top a 2 elements of the stack
 * @stack: refers to the pointer to the stack
 * @line_number: line no. where the add function is called
 * Return: returns nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;

	if (global_args->stack_length < 2)
	{
		dprintf(2, "L%d: can't sub, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->head;
	temp2 = temp1->next;

	temp2->n = temp2->n - temp1->n;
	remove_stack_node();

	global_args->stack_length -= 1;
}
/**
 * mul - function multiplies the top a 2 elements of the stack
 * @stack: refers to the pointer to the stack
 * @line_number: line no. where the add function is called
 * Return: returns nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;

	if (global_args->stack_length < 2)
	{
		dprintf(2, "L%d: can't mul, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->head;
	temp2 = temp1->next;

	temp2->n = temp1->n * temp2->n;
	remove_stack_node();

	global_args->stack_length -= 1;
}
/**
 * _div - function divides the top a 2 elements of the stack
 * @stack: refers to the pointer to the stack
 * @line_number: line no. where the add function is called
 * Return: returns nothing
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp1, *temp2;

	(void)stack;

	if (global_args->stack_length < 2)
	{
		dprintf(2, "L%d: can't div, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp1 = global_args->head;
	temp2 = temp1->next;

	if (temp1->n == 0)
	{
		dprintf(2, "L%d: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp2->n = temp2->n / temp1->n;
	remove_stack_node();

	global_args->stack_length -= 1;
}
/**
 * mod - function compute modulo of the top a 2 elements of the stack
 * @stack: refers to the pointer to the stack
 * @line_number: line no. where the add function is called
 * Return: returns nothing
 */
void mod(stack_t **stack, unsigned int line_number)
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

	if (temp1->n == 0)
	{
		dprintf(2, "L%d: division by zero", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	temp2->n = temp2->n % temp1->n;
	remove_stack_node();

	global_args->stack_length -= 1;
}
