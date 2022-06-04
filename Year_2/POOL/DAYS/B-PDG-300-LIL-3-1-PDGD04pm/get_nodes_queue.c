/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** get_nodes_queue
*/

#include "list.h"
#include "queue.h"

void *queue_front(queue_t queue)
{
    return (list_get_elem_at_front(queue));
}
