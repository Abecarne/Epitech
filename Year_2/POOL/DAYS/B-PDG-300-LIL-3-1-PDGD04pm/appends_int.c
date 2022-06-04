/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** appends
*/

#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t temp = (int_list_t)malloc(sizeof(int_list_t));

    if (!temp)
        return (false);
    temp->value = elem;
    temp->next = *front_ptr;
    *front_ptr = temp;
    return (true);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t new_node = (int_list_t)malloc(sizeof(int_list_t));
    int_list_t last = *front_ptr;

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

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
                                        unsigned int position)
{
    int_list_t new_node = malloc(sizeof(int_list_t));
    int_list_t tmp = *front_ptr;

    if (!new_node)
        return (false);
    new_node->value = elem;
    if (position == 0) {
        return (int_list_add_elem_at_front(front_ptr, elem));
    }
    for (unsigned int i = 0; i < position - 1; i++) {
    	tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
    return (true);
}