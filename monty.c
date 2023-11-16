#include "monty.h"

/**
 * main - Entry point of the program
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
stack_t *head = NULL;
int line_number;
char *opcode;
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!open_file(argv[1]))
    {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    free_nodes();
    return EXIT_SUCCESS;
}
