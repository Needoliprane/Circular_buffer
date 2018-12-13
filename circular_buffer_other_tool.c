/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** cicular_buffer_other_tool
*/

#include <unistd.h>
#include "circular_buffer.h"

int my_strlen(char *str);

void flush_circular_buffer(circular_buffer_t *cb)
{
    int size = my_strlen(cb->buffer);

    write(1, cb->buffer, size);
    cb->write = 0;
    for (int i = 0; i <= size + 1; i++)
        cb->buffer[i] = '\0';
}