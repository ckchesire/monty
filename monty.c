#include "monty.h"
global_t *global_args = NULL;
/**
 * main - entry point of the program
 * @argc: number of command line arguments passed
 * @argv: pointer to array of command line argument variables passed
 * Return: returns '0' if successful
 */
int main(int argc, char **argv)
{
	size_t n = 0;

	validate_argc(argc);
	initialize_args();
	get_file_stream(argv[1]);

	while (getline(&global_args->f_line, &n, global_args->f_stream) != -1)
	{
		global_args->line_number += 1;
		tokenize_line();
		get_instruction();
		run_instruction();
		free_tokens();
	}
	close_stream();
	free_args();
	return (0);
}
