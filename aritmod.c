#include "monty.h"

/**
 * get_module - Gets the remainder of the division of the second top element
 *              of the stack by the top element.
 * @head: Double pointer to the header (top) of the stack.
 * @line_number: Counter for the line number of the file.
 *
 * Return: void.
 */
void get_module(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    int num_nodes = 1; /* Number of elements in stack */

    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    while (current->next != NULL)
    {
        current = current->next;
        num_nodes++;
    }

    if (num_nodes + 1 <= 2)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head; /* Set current to head to perform modulo */

    if (current->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    current->next->n %= current->n; /* Perform the modulo operation */

    *head = current->next;
    free(current);
    current->prev = NULL;
}
