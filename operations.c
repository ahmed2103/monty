#include "monty.h"
/**
 * execute_opcode - Reads an opcode and verifies if it is valid
 * @stack: Double pointer to the header (top) of the stack
 * @line_number: Counter for the line number of the file
 * @code: Opcode to execute
 *
 * Return: void
 */
void execute_opcode(stack_t **stack, unsigned int line_number, char *code)
{
    int i = 0;
    instruction_t opcode_func[] = {
		{"add", add_top_two_elements},
		{"div", divide_second_by_top},
		{"mod", get_module},
		{"mul", multiply_top_with_second},
		{"nop", _nop},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"push", push},
		{"sub", subtract_top_from_second},
		{"swap", swap},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotr", rotr},
		{"rotl", rotl},
		{"stack", _stack},
		{"queue", queue},
		{NULL, NULL}
	};

 	while (opcode_func[i].opcode)
 	{
    	if (strcmp(opcode_func[i].opcode, code) == 0)
		{
        	opcode_func[i].f(stack, line_number);
        	return;
        }
        i++;
    }

    dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_number, code);
    free_stack(*stack);
    exit(EXIT_FAILURE);
}

/**
 * free_stack - Frees a stack
 * @head: Pointer to the head of the stack
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
    stack_t *temp;

    while (head != NULL)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}
/**
 * _nop - The opcode nop doesn't do anything.
 * @head: Double pointer to the header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void _nop(stack_t **head, unsigned int line_number)
{
    (void)head;          /* Avoid compiler warnings about unused parameters */
    (void)line_number;   /* Avoid compiler warnings about unused parameters */
}
/**
 * pall - Prints all elements in the stack.
 * @stack: Double pointer to the header (top) of the stack.
 * @line_number: Counter for line number of the file.
 *
 * Return: void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void)line_number; // Avoids warnings about an unused variable

    current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
