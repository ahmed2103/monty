#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to header (top) of the stack.
 * @line_number: counter for line number of the file.
 *
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
        free_stack_t(*stack);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * stack - Selects stack mode (default).
 * @stack: Double pointer to header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void stack(stack_t **stack, unsigned int line_number)
{
    (void) stack;
    (void) line_number;
    stack_queue = 's';
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack || !((*stack)->next))
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    if ((*stack)->next)
        ((*stack)->next)->prev = temp;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
    temp->prev = *stack;
}
