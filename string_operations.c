#include "monty.h"

/**
 * print_character - Prints the ASCII character value.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void print_character(stack_t **stack, unsigned int line)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		handle_error(PCHAR_EMPTY_STACK_ERROR);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		handle_error(PCHAR_OUT_OF_RANGE_ERROR);

	printf("%c\n", ascii);
}

/**
 * print_string - Prints a string.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void print_string(stack_t **stack, unsigned int line)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotate_left - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void rotate_left(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
