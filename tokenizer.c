#include "monty.h"

/**
 * tokenize_line - function breaks up a line into words
 * Return: returns nothing
 */
void tokenize_line(void)
{
	int i = 0;
	char *delims = " \n";
	char *token = NULL, *linecopy = NULL;

	linecopy = malloc(sizeof(char) * (strlen(global_args->f_line) + 1));
	strcpy(linecopy, global_args->f_line);
	global_args->n_tokens = 0;
	token = strtok(linecopy, delims);
	while (token)
	{
		global_args->n_tokens += 1;
		token = strtok(NULL, delims);
	}
	global_args->tokens = malloc(sizeof(char *) * (global_args->n_tokens + 1));
	strcpy(linecopy, global_args->f_line);
	token = strtok(linecopy, delims);
	while (token)
	{
		global_args->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));

		if (global_args->tokens[i] == NULL)
			malloc_fail();
		strcpy(global_args->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	global_args->tokens[i] = NULL;
	free(linecopy);
}
