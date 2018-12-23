/*
** EPITECH PROJECT, 2018
** Buffer Ciruclaire
** File description:
** circular_buffer
*/

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

/* Include */


/* Struct */

typedef struct circular_buffer_s {
    char *buffer;
    int read;
    int write;
    int size;
} circular_buffer_t;

/* Create */

int size_helper(char **tab);
circular_buffer_t *create_circular_buffer(int size);

/* Fill */

int add_queue_circular_buffer(circular_buffer_t *cb, char *str);

/* Read */

int read_circular_buffer(circular_buffer_t *cb);

/* Flush */

void flush_circular_buffer(circular_buffer_t *cb);
void check_flush(int counter, int value, circular_buffer_t *cb);

/* Destroy */

void destroy_circular_buffer(circular_buffer_t *cb);

#endif /* !CIRCULAR_BUFFER_H_ */