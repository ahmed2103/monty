#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

 Struct for the stack node 
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

 Error handling codes 
#define USAGE_ERROR 1
#define FILE_OPEN_ERROR 2
#define FILE_READ_ERROR 3
#define MALLOC_ERROR 4
#define PUSH_FORMAT_ERROR 5
#define UNKNOWN_OPCODE_ERROR 6
#define PINT_ERROR 7
#define POP_ERROR 8
#define SHORT_STACK_ERROR 9
#define DIV_ZERO_ERROR 10
#define PCHAR_RANGE_ERROR 11
#define PCHAR_EMPTY_ERROR 12

/**
 * Global variables
 */
extern stack_t *head;
extern int line_number;
extern char *opcode;

/**
 * Function prototypes
 */
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int line);
void push_stack(stack_t **new_node, unsigned int line);
void push_queue(stack_t **new_node, unsigned int line);

void callopcode(op_func func, char *opcode, char *value, int line, int format);
void print_top_value(stack_t **stack, unsigned int line);
void pop_top_node(stack_t **stack, unsigned int line);
void no_operation(stack_t **stack, unsigned int line);
void swap_top_nodes(stack_t **stack, unsigned int line);

void add_to_queue(stack_t **new_node, unsigned int line);

void print_character(stack_t **stack, unsigned int line);
void print_string(stack_t **stack, unsigned int line);
void rotate_left(stack_t **stack, unsigned int line);

void handle_error(int error_code);

#endif /* MONTY_H */
