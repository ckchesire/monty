#include "monty.h"
/**
 * initialize_args - initalizes memory for pointer to global_s structure
 * Return: nothing
 */
void initialize_args(void)
{
	global_args = (global_t *)malloc(sizeof(global_t));

	if (global_args == NULL)
		malloc_fail();

	global_args->instruction = (instruction_t *)malloc(sizeof(instruction_t));
	if (global_args->instruction == NULL)
		malloc_fail();

	global_args->f_stream = NULL;
	global_args->f_line = NULL;
	global_args->n_tokens = 0;
	global_args->line_number = 0;
	global_args->head = NULL;
	global_args->stack_length = 0;
}

/**
 * malloc_fail - error handling when malloc fails to allocate memory
 * Return: returns nothing
 */
void malloc_fail(void)
{
	dprintf(2, "Error: malloc failed\n");
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * free_args - function to free allocated memory
 * Return: returns nothing
 */
void free_args(void)
{
	if (global_args == NULL)
		return;
	if (global_args->instruction)
	{
		free(global_args->instruction);
		global_args->instruction = NULL;
	}

	if (global_args->head)
		free_stack(global_args->head);
	global_args->head = NULL;

	if (global_args->f_line)
	{
		free(global_args->f_line);
		global_args->f_line = NULL;
	}
	free(global_args);
}

/**
 * free_stack - free the nodes in a stack list
 * @head: the fist node of double linked list
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;

	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}

/**
 * free_all - free all the allocated memory  for arguments
 * Return: returns nothing
 */
void free_all(void)
{
	close_stream();
	free_tokens();
	free_args();
}
