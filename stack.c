void print_top_value(stack_t **stack, unsigned int line)
{
    if (stack == NULL || *stack == NULL)
        handle_error(PINT_ERROR, line);
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
        handle_error(POP_ERROR, line);

    tmp = *stack;
    *stack = tmp->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(tmp);
}

/**
 * do_nothing - Does nothing.
 * @stack: Pointer to a pointer to the stack's top node.
 * @line: Line number of the opcode.
 */
void do_nothing(stack_t **stack, unsigned int line)
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
        handle_error(SHORT_STACK_ERROR, line);

    tmp = (*stack)->next;
    (*stack)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *stack;
    tmp->next = *stack;
    (*stack)->prev = tmp;
    tmp->prev = NULL;
    *stack = tmp;
}

/**
 * add_to_queue - Adds a new node to the queue.
 * @new_node: Pointer to the new node.
 * @line: Line number of the opcode.
 */
void add_to_queue(stack_t **new_node, unsigned int line)
{
    if (!new_node || !*new_node)
        handle_error(MEM_ALLOC_FAIL, line);

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
