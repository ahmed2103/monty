stack_t *head = NULL;
#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		handle_error(USAGE_ERROR);

	open_file(argv[1]);
	free_nodes();

	return (0);
}
