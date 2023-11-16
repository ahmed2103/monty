#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
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

 Function prototypes 

 File operations 
void open_file(char file_name);
void read_file(FILE fd);
int len_chars(FILE fd);
int interpret_line(char lineptr, int line_number, int format);
void find_func(char opcode, char value, int ln, int format);

 Stack operations 
stack_t create_node(int n);
void free_nodes(void);
void print_stack(stack_t stack, unsigned int line_number);
void add_to_stack(stack_t stack, unsigned int line_number);
void add_to_queue(stack_t stack, unsigned int line_number);

 Error handling 
void handle_error(int error_code);

 Other operations 
void call_fun(op_func f, char op, char val, int ln, int format);
void print_top(stack_t stack, unsigned int line_number);
void pop_top(stack_t stack, unsigned int line_number);
void nop(stack_t stack, unsigned int line_number);
void swap_nodes(stack_t stack, unsigned int line_number);

 Arithmetic operations 
void add_nodes(stack_t stack, unsigned int line_number);
void sub_nodes(stack_t stack, unsigned int line_number);
void div_nodes(stack_t stack, unsigned int line_number);
void mul_nodes(stack_t stack, unsigned int line_number);
void mod_nodes(stack_t stack, unsigned int line_number);

 String operations 
void print_char(stack_t stack, unsigned int line_number);
void print_str(stack_t stack, unsigned int line_number);
void rotl(stack_t stack, unsigned int line_number);
void rotr(stack_t stack, unsigned int line_number);

#endif  MONTY_H 
