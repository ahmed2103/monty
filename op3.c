#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void push(stack_t **stack, unsigned int line_number)
{
    size_t len = 0, i = 0;
    char arg[128] = "";
    char *argument = arg;

    argument = strtok(NULL, " \t\r\n\v\f");

    if (argument == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    len = strlen(argument);
    for (i = 0; i < len; i++)
        if (!isdigit(argument[i]) && argument[0] != '-')
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }

    if (stack_queue == 's')
        add_node(stack, atoi(argument));

    if (stack_queue == 'q')
        add_node_queue(stack, atoi(argument));
}

/**
 * add_node -  pushes an element to the stack.
 * @stack: double pointer to header (top) of the stack.
 * @argument: integer push.
 *
 * Return: void.
 */
void add_node(stack_t **stack, int argument)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);

		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}


/**
 * add_node_queue - Pushes an element to the stack.
 * @stack: Double pointer to header (top) of the stack.
 * @argument: Integer to push.
 *
 * Return: void.
 */
void add_node_queue(stack_t **stack, int argument)
{
	stack_t *new_node = NULL, *last = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);

		exit(EXIT_FAILURE);
	}

	new_node->n = argument;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		new_node->next = NULL;
		new_node->prev = last;
		last->next = new_node;
	}
}
/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void) line_number;
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;
    while (last->next != NULL)
        last = last->next;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    temp->next = NULL;
    temp->prev = last;
    last->next = temp;
}
/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void) line_number;
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    last = *stack;
    while (last->next != NULL)
        last = last->next;

    temp = *stack;
    *stack = last;
    (*stack)->prev->next = NULL;
    (*stack)->prev = NULL;
    (*stack)->next = temp;
    temp->prev = *stack;
}
