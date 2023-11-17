#include "monty.h"

/**
 * call_opcode_function - Calls the appropriate opcode function.
 * @func: Function pointer to the opcode function.
 * @opcode: Opcode string.
 * @value: Value string associated with the opcode.
 * @line: Line number of the opcode.
 * @format: Stack format specifier (STACK_FORMAT or QUEUE_FORMAT).
 */
void callopcode(op_func func, char *opcode, char *value, int line, int format)
{
    stack_t *node;
    int flag, i;

    flag = 1;
    if (strcmp(opcode, "push") == 0)
    {
        if (value != NULL && value[0] == '-')
        {
            value = value + 1;
            flag = -1;
        }
        if (value == NULL)
            handle_error(PUSH_FORMAT_ERROR, line);
        for (i = 0; value[i] != '\0'; i++)
        {
            if (isdigit(value[i]) == 0)
                handle_error(PUSH_FORMAT_ERROR, line);
        }
        node = create_node(atoi(value) * flag);
        if (format == STACK_FORMAT)
            func(&node, line);
        if (format == QUEUE_FORMAT)
            add_to_queue(&node, line);
    }
    else
    {
        func(&head, line);
    }
}
