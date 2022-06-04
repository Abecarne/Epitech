/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** get_nodes
*/

#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    int_list_t tmp = list;

    if (list == NULL)
        return (0);
    while (tmp->next != NULL)
        tmp = tmp->next;
    return (tmp->value);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    int_list_t tmp = list;
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
