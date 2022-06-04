/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** appends_list
*/

#include "list.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t temp = (list_t)malloc(sizeof(list_t));

    if (!temp)
        return (false);
    temp->value = elem;
    temp->next = *front_ptr;
    *front_ptr = temp;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new_node = (list_t)malloc(sizeof(list_t));
    list_t last = *front_ptr;

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = NULL;

    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return (false);
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new_node;
    }
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem, unsigned int pos)
{
    list_t new_node = malloc(sizeof(list_t));
    list_t tmp = *front_ptr;

    if (!new_node)
        return (false);
    new_node->value = elem;
    if (pos == 0) {
        return (list_add_elem_at_front(front_ptr, elem));
    }
    for (unsigned int i = 0; i < pos - 1; i++) {
    	tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
    return (true);
}