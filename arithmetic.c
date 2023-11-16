#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void add(stack_t **stack, unsigned int line_number) {
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "add");

    (*stack) = (*stack)->next;
    (*stack)->n += (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * sub - Subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void sub(stack_t **stack, unsigned int line_number) {
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "sub");

    (*stack) = (*stack)->next;
    (*stack)->n -= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void mul(stack_t **stack, unsigned int line_number) {
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "mul");

    (*stack) = (*stack)->next;
    (*stack)->n *= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}

/**
 * div_op - Divides the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the opcode.
 */
void div_op(stack_t **stack, unsigned int line_number) {
    if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
        more_err(8, line_number, "div");

    if ((*stack)->n == 0)
        more_err(9, line_number);

    (*stack) = (*stack)->next;
    (*stack)->n /= (*stack)->prev->n;
    free((*stack)->prev);
    (*stack)->prev = NULL;
}
