#include "monty.h"
/**
 * validate_argc - validates command-line arguments passed by the user
 * @argc: number of command-line arguments passed by the user
 * Return: returns nothing
 */
void validate_argc(int argc)
{
	if (argc == 2)
		return;

	dprintf(2, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
