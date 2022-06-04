/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** delete
*/

#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

bool int_list_is_empty(int_list_t list);

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;

    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;
    int_list_t del;

    if (*front_ptr == NULL) {
        if ((*front_ptr)->next == NULL) {
            *front_ptr = NULL;
            return (false);
        }
    } else {
        while (tmp->next->next != NULL)
            tmp = tmp->next;
        del = tmp->next;
        tmp->next = NULL;
        free(del);
    }
    return (true);
}

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_list_t tmp = *front_ptr;
    unsigned int count = 0;

    if (position == 0)
        return (int_list_del_elem_at_front(front_ptr));
    if (*front_ptr == NULL)
        return (false);
    while (tmp->next != NULL) {
        if (count == position - 1) {
            tmp->next = tmp->next->next;
            return (true);
        }
        tmp = tmp->next;
        count++;
    }
    return (true);
}

void int_list_clear(int_list_t *front_ptr)
{
    int_list_t tmp = *front_ptr;

    while (*front_ptr != NULL) {
        tmp = *front_ptr;
        *front_ptr = (*front_ptr)->next;
        free(tmp);
    }
}
