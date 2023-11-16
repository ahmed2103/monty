#include "monty.h"

/**
 * open_file - Opens a file and handles potential errors.
 * @file_name: The name of the file to be opened.
 */
void open_file(char *file_name)
{
    FILE *file = fopen(file_name, "r");

    if (file == NULL)
        handle_error(FILE_OPEN_ERROR);

    read_file(file);
    fclose(file);
}

/**
 * read_file - Reads the content of a file line by line.
 * @fd: Pointer to a file descriptor of an open file.
 */
void read_file(FILE *fd)
{
    char *lineptr = NULL;
    size_t n = 0;
    int line_number = 1;

    if (fd == NULL)
        handle_error(FILE_READ_ERROR);

    while (getline(&lineptr, &n, fd) != -1)
    {
        int format = interpret_line(lineptr, line_number++, 0);
    }
    free(lineptr);
}

/**
 * len_chars - Determines the length of characters in a file.
 * @file: Pointer to a file to determine length.
 * Return: The number of characters in the file.
 */
int len_chars(FILE *file)
{
    int length = 0;

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    rewind(file);
    return (length);
}

/**
 * interpret_line - Separates each line into tokens to determine
 * @lineptr: String representing a line in a file.
 * @line_number: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 *          if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int interpret_line(char *lineptr, int line_number, int format)
{
    const char *delim = "\n ";
    char *opcode = strtok(lineptr, delim);

    if (opcode == NULL)
        return (format);

    char *value = strtok(NULL, delim);

    if (strcmp(opcode, "queue") == 0)
        return (1);
    else if (strcmp(opcode, "stack") == 0)
        return (0);

    find_func(opcode, value, line_number, format);
    return (format);
}

/**
 * find_func - Finds the appropriate function to run the opcode instructions.
 * @opcode: The operation code, e.g., push, pall, ...
 * @value: The possible value for the operation.
 * @line_number: Line number for the opcode.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 *          if 1 nodes will be entered as a queue.
 */
