#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#define INITIAL_BUFFER_SIZE 128

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
extern char stack_queue;

void add_top_two_elements(stack_t **stack, unsigned int line_number);
void subtract_top_from_second(stack_t **head, unsigned int line_number);
void multiply_top_with_second(stack_t **head, unsigned int line_number);
void get_module(stack_t **head, unsigned int line_number);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void _nop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void divide_second_by_top(stack_t **head, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

void _stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);

void execute_opcode(stack_t **stack, unsigned int line_number, char *code);
char **token_opcode(char *line);
void free_stack(stack_t *head);
void add_node(stack_t **stack, int argument);
void add_node_queue(stack_t **stack, int argument);

#endif
