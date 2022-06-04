/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** get_nodes_list
*/

#include "list.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    list_t tmp = list;

    if (list == NULL)
        return (0);
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    list_t tmp = list;
    unsigned int count = 0;

    if (list == NULL)
        return (0);
    while (tmp->next != NULL) {
        if (count == position)
            return (tmp->value);
        count++;
        tmp = tmp->next;
    }
    return (0);
}