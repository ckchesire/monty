#include "monty.h"
/**
 * free_tokens - function frees all allocated memeory for tokens
 * Return: returns nothing
 */
void free_tokens(void)
{
	int i = 0;

	if (global_args->tokens == NULL)
		return;

	while (global_args->tokens[i])
	{
		free(global_args->tokens[i]);
		i++;
	}
	free(global_args->tokens);
	global_args->tokens = NULL;
}

/**
 * close_stream - function closes the file stream and sets it to NULL
 * Return: return nothing
 */
void close_stream(void)
{
	if (global_args->f_stream == NULL)
		return;
	fclose(global_args->f_stream);
	global_args->f_stream = NULL;
}
