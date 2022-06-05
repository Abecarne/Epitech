/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** linked_list2
*/

#include "../include/main.h"

void maybe_remove(client_t *list, client_t *tmp, int fd_to_rm, client_t *prev)
{
    if (tmp->fd == fd_to_rm) {
        if (!prev)
            list = list->next;
        else
            prev->next = tmp->next;
        free_client(tmp);
    }
}
