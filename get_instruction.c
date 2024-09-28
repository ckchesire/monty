#include "monty.h"
/**
 * get_instruction - function to set instruction based on the first token
 * Return: returns nothing
 */
void get_instruction(void)
{
	int i = 0;
	instruction_t instructions[] = {
		{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"sub", &sub},
		{"div", &_div}, {"mul", &mul},
		{"mod", &mod},
		/*
		* {"rotl", &rotl}, {"rotr", &rotr},
		* {"stack", &stack}, {"queue", &queue},
		* {"pstr", &pstr}, {"pchar", &pchar},
		*/
		{NULL, NULL}
	};

	if (global_args->n_tokens == 0)
		return;

	for (; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(instructions[i].opcode, global_args->tokens[0]) == 0)
		{
			global_args->instruction->opcode = instructions[i].opcode;
			global_args->instruction->f = instructions[i].f;
			return;
		}
	}
	unknown_instruction();
}

/**
 * unknown_instruction - funtion handles invalid instruction
 * Return: returns nothing
 */
void unknown_instruction(void)
{
	dprintf(2, "L%d: unknown instruction %s\n",
			global_args->line_number, global_args->tokens[0]);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * run_instruction - funtion runs the instruction specified by the arguments
 * Return: returns nothing
 */
void run_instruction(void)
{
	stack_t *stack = NULL;

	if (global_args->n_tokens == 0)
		return;
	global_args->instruction->f(&stack, global_args->line_number);
}
