/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** delete_list
*/

#include "list.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t tmp = *front_ptr;

    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t tmp = *front_ptr;
    list_t del;

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

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    list_t tmp = *front_ptr;
    unsigned int count = 0;

    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
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

void list_clear(list_t *front)
{
    list_t tmp = *front;

    while (*front != NULL) {
        tmp = *front;
        *front = (*front)->next;
        free(tmp);
    }
}