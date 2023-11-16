#include "monty.h"

/**
 * call_opcode_function - Calls the appropriate opcode function.
 * @func: Function pointer to the opcode function.
 * @opcode: Opcode string.
 * @value: Value string associated with the opcode.
 * @line: Line number of the opcode.
 * @format: Stack format specifier (stack or queue).
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
			handle_error(PUSH_FORMAT_ERROR);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				handle_error(PUSH_FORMAT_ERROR);
		}
		node = create_node(atoi(value) * flag);
		if (format == 0)
			func(&node, line);
		if (format == 1)
			add_to_queue(&node, line);
	}
	else
		func(&head, line);
}

/**
 * print_top_value - Prints the value at the top of the stack.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void print_top_value(stack_t **stack, unsigned int line)
{
	if (stack == NULL || *stack == NULL)
		handle_error(PINT_ERROR);
	printf("%d\n", (*stack)->n);
}

/**
 * pop_top_node - Removes the top node from the stack.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void pop_top_node(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		handle_error(POP_ERROR);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * no_operation - Does nothing.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void no_operation(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * swap_top_nodes - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void swap_top_nodes(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		handle_error(SHORT_STACK_ERROR);

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
