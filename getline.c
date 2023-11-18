#include "monty.h"
/**
 * _getline - Read a line from a file stream
 * @lineptr: Pointer to the buffer containing the line read
 * @n: Pointer to the size of the buffer
 * @stream: File stream to read from
 *
 * Return: Number of characters read, -1 on failure
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    int index = 0;
    int ch;
    int i;
    char *temp;
    
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    if (*lineptr == NULL || *n == 0) {
        *n = INITIAL_BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;
        }
    }
    while ((ch = fgetc(stream)) != EOF && ch != '\n') {
        (*lineptr)[index++] = ch;

        if ((size_t)index >= *n - 1) {
            *n *= 2;
            temp = (char *)malloc(*n);
            if (temp == NULL) {
                return -1;
            }

            for (i = 0; i < index; i++) {
                temp[i] = (*lineptr)[i];
            }

            free(*lineptr);
            *lineptr = temp;
        }
    }

    if (index == 0 && ch == EOF) {
        return -1;
    }

    (*lineptr)[index] = '\0';

    if (ch == EOF) {
    }

    return index;
}
