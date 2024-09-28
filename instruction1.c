#include "monty.h"
/**
 * push - function pushes an integer onto a stack
 * @stack: the stack pointer
 * @line_number: line where the push function has been called
 * Return: returns nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (global_args->n_tokens <= 1 || !(is_number(global_args->tokens[1])))
	{
		free_args();
		dprintf(2, "L%d: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_fail();
	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int)atoi(global_args->tokens[1]);

	if (global_args->head != NULL)
	{
		(*stack)->next = global_args->head;
		global_args->head->prev = *stack;
	}
	global_args->head = *stack;
	global_args->stack_length += 1;
}

/**
 * pall - lists all the elements in the stack
 * @stack: pointer to the stack
 * @line_number: line number where pall function is retieved
 * Return: return nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (global_args->head == NULL)
		return;

	(void) line_number;
	(void) stack;

	temp = global_args->head;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: the stack pointer
 * @line_number: line where the push function has been called
 * Return: return nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	if (global_args->head == NULL)
	{
		dprintf(2, "L%d:: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", global_args->head->n);
}

/**
 * is_number - checks if string is an integer number
 * @str: string to be reviewed
 * Return: return '1' if true '0' if false
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
