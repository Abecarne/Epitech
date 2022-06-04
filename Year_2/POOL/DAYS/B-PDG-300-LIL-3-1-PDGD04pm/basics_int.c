/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** basics
*/

#include "int_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


unsigned int int_list_get_size(int_list_t list)
{
    int_list_t head = list;
    int res = 0;

    while (head != NULL) {
        head = head->next;
        res++;
    }
    return (res);
}

bool int_list_is_empty(int_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void int_list_dump(int_list_t list)
{
    int_list_t head = list;

    while (head != NULL) {
        printf("%d\n", head->value);
        head = head->next;
    }
}
