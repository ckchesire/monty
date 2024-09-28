#include "monty.h"
/**
 * read_file_failed - function to handle error when unable to read file
 * @fileName: file name of the file that failed to open
 * Returns: returns nothing
 */
void read_file_failed(char *fileName)
{
	dprintf(2, "Error: Can't open file %s\n", fileName);
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * get_file_stream - gets the stream from reading a file
 * @fileName: file name of the file to open and stream
 * Returns: returns nothing
 */
void get_file_stream(char *fileName)
{
	int fd;

	fd = open(fileName, O_RDONLY);
	if (fd == -1)
		read_file_failed(fileName);

	global_args->f_stream = fdopen(fd, "r");
	if (global_args->f_stream == NULL)
	{
		close(fd);
		read_file_failed(fileName);
	}
}
