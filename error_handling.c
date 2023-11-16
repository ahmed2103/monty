#include "monty.h"

void nested_error(int error_code)
{
    switch (error_code)
    {
    case POP_ERROR:
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        break;
    case SHORT_STACK_ERROR:
        fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
        break;
    case DIV_ZERO_ERROR:
        fprintf(stderr, "L%d: division by zero\n", line_number);
        break;
    case PCHAR_RANGE_ERROR:
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        break;
    case PCHAR_EMPTY_ERROR:
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        break;
    default:
        break;
    }
}

/**
 * handle_error - Prints an error message and exits the program.
 * @error_code: Error code for identifying the error.
 */
void handle_error(int error_code)
{
    switch (error_code)
    {
    case USAGE_ERROR:
        fprintf(stderr, "USAGE: monty file\n");
        break;
    case FILE_OPEN_ERROR:
        fprintf(stderr, "Error: Can't open file\n");
        break;
    case FILE_READ_ERROR:
        fprintf(stderr, "Error: Can't read file\n");
        break;
    case MALLOC_ERROR:
        fprintf(stderr, "Error: malloc failed\n");
        break;
    case PUSH_FORMAT_ERROR:
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        break;
    case UNKNOWN_OPCODE_ERROR:
        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
        break;
    case PINT_ERROR:
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        break;
    default:
        break;
    }

    nested_error(error_code);
    free_nodes();
    exit(EXIT_FAILURE);
}
