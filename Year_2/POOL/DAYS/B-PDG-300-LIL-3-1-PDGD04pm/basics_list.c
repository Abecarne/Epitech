/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** basics_list
*/

#include "list.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

unsigned int list_get_size(list_t list)
{
    list_t head = list;
    int res = 0;

    while (head != NULL) {
        head = head->next;
        res++;
    }
    return (res);
}

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    list_t tmp = list;

    while (tmp != NULL) {
        val_disp(tmp->value);
        tmp = tmp->next;
    }
}
