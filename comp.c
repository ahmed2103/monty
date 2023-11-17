#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        free_stack_t(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    if ((*stack)->next)
        (*stack)->next->prev = NULL;
    *stack = (*stack)->next;
    free(current);
}
#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    int n;
    stack_t *temp = *stack;

    (void) line_number;
    if (*stack == NULL)
    {
        printf("\n");
        return;
    }

    while (temp != NULL)
    {
        n = temp->n;
        if (!(n >= 1 && n <= 127) || n == 0)
            break;
        printf("%c", n);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * pchar - Prints the character at the top of the stack as ASCII, followed by a new line.
 * @stack: Double pointer to the header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    int n;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        free_stack_t(*stack);
        exit(EXIT_FAILURE);
    }

    n = (*stack)->n;
    if (n >= 32 && n <= 127)
        printf("%c\n", n);
    else
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        free_stack_t(*stack);
        exit(EXIT_FAILURE);
    }
}
