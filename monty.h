#ifndef MONTY
#define MONTY

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - holds the variables during program exec
 * @f_stream: pointer file stream will connect to the stream of opened file
 * @f_line: line of text read from stream or file input
 * @line_number: used for tracking the current line number
 * @tokens: used to store tokens retrieved from a line
 * @n_tokens: total count of tokens created from a line
 * @instruction: valid instruction retrieved from a line
 * @head: pointer to the current node
 * @stack_length: length of the stack
 *
 * Description: stores variables that will be used  in different functions
 * of the program as well as variables that will require memory allocation
 * and freeing.
 */
typedef struct global_s
{
	FILE *f_stream;
	char *f_line;
	unsigned int line_number;
	char **tokens;
	int n_tokens;
	instruction_t *instruction;
	stack_t *head;
	unsigned int stack_length;
} global_t;

extern global_t *global_args;

void validate_argc(int argc);
void initialize_args(void);
void malloc_fail(void);
void read_file_failed(char *fileName);
void get_file_stream(char *fileName);
void free_args(void);
void tokenize_line(void);
void get_instruction(void);
void unknown_instruction(void);
void free_tokens(void);
void close_stream(void);
void run_instruction(void);
int is_number(char *str);
void free_all(void);
void free_stack(stack_t *head);
void delete_stack_node(void);

void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
/*
 * void add(stack_t **stack, unsigned int line_number);
 * void nop(stack_t **stack, unsigned int line_number);
 * void sub(stack_t **stack, unsigned int line_number);
 * void _div(stack_t **stack, unsigned int line_number);
 * void mul(stack_t **stack, unsigned int line_number);
 * void mod(stack_t **stack, unsigned int line_number);
 * void pchar(stack_t **stack, unsigned int line_number);
 * void pstr(stack_t **stack, unsigned int line_number);
 * void rotl(stack_t **stack, unsigned int line_number);
 * void rotr(stack_t **stack, unsigned int line_number);
 * void stack(stack_t **stack, unsigned int line_number);
 * void queue(stack_t **stack, unsigned int line_number);
 */

#endif /* MONTY */
