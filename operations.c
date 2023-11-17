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
    instruction_t opcodes[] = {
        {"add", add},
        {"div", divide},
        {"mod", modulo},
        {"mul", multiply},
        /* Add other opcodes here */
        {NULL, NULL}
    };

    while (opcodes[i].opcode)
    {
        if (strcmp(opcodes[i].opcode, code) == 0)
        {
            opcodes[i].f(stack, line_number);
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
