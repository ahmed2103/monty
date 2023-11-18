#include "monty.h"

char stack_queue = 's';

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of strings containing the arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *stream = NULL;
    size_t len = 0;
    unsigned int line_number = 1;
    char *line = NULL;
    char *code = NULL;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    stream = fopen(argv[1], "r");
    if (stream == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, stream) != -1)
    {
        code = strtok(line, " \t\r\n\v\f");
        if (code != NULL && code[0] != '#')
            execute_opcode(&stack, line_number, code);
        line_number++;
    }

    free_stack(stack);
    free(line);
    fclose(stream);
    return EXIT_SUCCESS;
}
