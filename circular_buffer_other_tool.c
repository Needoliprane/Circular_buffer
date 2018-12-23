/*
** EPITECH PROJECT, 2018
** CPE_pushswap_2018
** File description:
** cicular_buffer_other_tool
*/

#include <unistd.h>
#include "circular_buffer.h"

void flush_circular_buffer(circular_buffer_t *cb)
{
    if (cb->write == 0)
        return;
    write(1, cb->buffer, cb->write);
    for (int i = 0; i <= cb->write + 1 && cb->buffer[i]; i++)
        cb->buffer[i] = '\0';
    cb->write = 0;
}

/* This function is useful when you don't know how much you have to write.
The counter is the number of time you call "add_queue_circular_buffer"
You have to choose value in depend of the size of the buffer
If you need exemple, let's check : 
https://github.com/Needoliprane/Push_Swap-EPITECH-2023
*/

void check_flush(int counter, int value, circular_buffer_t *cb)
{
    if (counter % value == 0)
        flush_circular_buffer(cb);
}