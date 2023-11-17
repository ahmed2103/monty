#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @stack: Double pointer to the header (top) of the stack.
 * @line_number: Counter for the line number of the file.
 *
 * Description: This function adds the top two elements of the stack.
 * If the stack has fewer than two elements, it prints an error message
 * and exits the program.
 *
 * Return: void.
 */
void add_top_two_elements(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_top;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp_top = *stack;
	*stack = (*stack)->next;
	(*stack)->n += temp_top->n;
	(*stack)->prev = NULL;
	free(temp_top);
}
/**
 * subtract_top_from_second - Subtracts the top element from the second top
 *                            element of the stack.
 * @head: Double pointer to the header (top) of the stack.
 * @line_number: Counter for the line number of the file.
 *
 * This function subtracts the value of the top element from the second top
 * element of the stack. If the stack is empty or has fewer than two elements,
 * it prints an error message and exits.
 *
 * Return: void.
 */
void subtract_top_from_second(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    int num_nodes = 1; /* Number of elements in stack */

    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
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
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    current = *head;
    current->next->n -= current->n;

    *head = current->next;
    free(current);
    current->prev = NULL;
}
/**
 * multiply_top_with_second - Multiplies the top element with the second top element of the stack.
 * @head: Pointer to the top of the stack.
 * @line_number: Line number where a wrong command was found.
 *
 * This function multiplies the value of the top element with the value of the second top element
 * of the stack. If the stack is empty or has fewer than two elements, it prints an error message
 * and exits the program.
 */
void multiply_top_with_second(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    int num_nodes = 1; /* Number of elements in stack */

    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
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
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head; /* Set current to head to perform multiplication */
    current->next->n *= current->n; /* Perform the multiplication */

    *head = current->next;
    free(current);
    current->prev = NULL;
}
/**
 * divide_second_by_top - Divides the second top element of the stack by the top element.
 * @head: Double pointer to the header (top) of the stack.
 * @line_number: Counter for the line number of the file.
 *
 * This function divides the value of the second top element of the stack by
 * the value of the top element. If the stack is empty or has fewer than two
 * elements, it prints an error message and exits. If the division by zero is
 * attempted, it also exits with an error message.
 *
 * Return: void.
 */
void divide_second_by_top(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;
    int num_nodes = 1; /* Number of elements in stack */

    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
        fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head; /* Set current to head to perform division */

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    current->next->n /= current->n; /* Perform the division */

    *head = current->next;
    free(current);
    current->prev = NULL;
}
