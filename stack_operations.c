#include "monty.h"

/**
 * create_node - Creates a new stack node.
 * @n: Integer value to be stored in the node.
 * Return: Pointer to the newly created node.
 */
stack_t *create_node(int n)
{
	stack_t *node = malloc(sizeof(stack_t));

	if (!node)
		handle_error(MEM_ALLOC_FAIL);

	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void)
{
	while (head)
	{
		stack_t *tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * print_stack - Prints all elements in the stack.
 * @stack: Pointer to the top of the stack.
 * @line: Line number (unused in this context).
 */
void print_stack(stack_t **stack, unsigned int line)
{
	(void)line;
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * push_stack - Pushes a new node onto the stack.
 * @new_node: Pointer to the new node.
 * @line: Line number (unused in this context).
 */
void push_stack(stack_t **new_node, unsigned int line)
{
	if (!new_node || !*new_node)
		handle_error(MEM_ALLOC_FAIL);

	stack_t *tmp = head;
	head = *new_node;
	head->next = tmp;

	if (tmp)
		tmp->prev = head;

	*new_node = NULL;
}

/**
 * push_queue - Pushes a new node into the queue.
 * @new_node: Pointer to the new node.
 * @line: Line number (unused in this context).
 */
void push_queue(stack_t **new_node, unsigned int line)
{
	if (!new_node || !*new_node)
		handle_error(MEM_ALLOC_FAIL);

	stack_t *tmp = head;

	if (!tmp)
	{
		head = *new_node;
		*new_node = NULL;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
	*new_node = NULL;
}
