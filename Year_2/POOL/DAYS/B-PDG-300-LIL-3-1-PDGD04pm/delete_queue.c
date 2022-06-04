/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** delete_queue
*/

#include "list.h"
#include "queue.h"

bool queue_pop(queue_t *queue_ptr)
{
    return (list_del_elem_at_back(queue_ptr));
}

void queue_clear(queue_t *queue_ptr)
{
    list_clear(queue_ptr);
}
