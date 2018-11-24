/*
** EPITECH PROJECT, 2018
** Buffer Ciruclaire
** File description:
** circular_buffer
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "circular_buffer.h"

int my_strlen(char *str);

void destroy_circular_buffer(circular_buffer_t *cb)
{
    free(cb->buffer);
    free(cb);
}

int size_helper(char **tab)
{
    int max = 0;
    int value = 0;

    for (int i = 0; tab[i]; i++) {
        value = my_strlen(tab[i]);
        if (value > max)
            max = value;
    }
    return (max);
}

circular_buffer_t *create_circular_buffer(int size)
{
    circular_buffer_t *cb = malloc(sizeof(circular_buffer_t));

    if (cb == NULL || size <= 0)
        return (NULL);
    cb->buffer = malloc(sizeof(char) * size + 1);
    if (cb->buffer == NULL)
        return (NULL);
    for (int i = 0; i <= size; i++)
        cb->buffer[i] = '\0';
    cb->read = 0;
    cb->write = 0;
    cb->size = size + 1;
    return (cb);
}

int read_circular_buffer(circular_buffer_t *cb)
{
    for (; cb->read != cb->write; cb->read++) {
        if (cb->read == cb->size)
            cb->read = 0;
        write(1, &cb->buffer[cb->read], 1);
    }
    return (0);
}

int add_queue_circular_buffer(circular_buffer_t *cb, char *str)
{
    for (int i = 0; str[i]; i++, cb->write++) {
        if (cb->write >= cb->size)
            cb->write = 0;
        cb->buffer[cb->write] = str[i];
    }
    return (0);
}

int main(int ac, char **av)
{
    circular_buffer_t *cb = NULL;
    int size = size_helper(av + 1);

    cb = create_circular_buffer(size);
    for (int i = 1; av[i]; i++) {
        add_queue_circular_buffer(cb, av[i]);
        printf("read_s : %c | write : %c | buffer : %s\n",cb->buffer[cb->read], cb->buffer[cb->write], cb->buffer);
        read_circular_buffer(cb);
        write(1, "\n", 1);
    }
    destroy_circular_buffer(cb);
    return (0);
}