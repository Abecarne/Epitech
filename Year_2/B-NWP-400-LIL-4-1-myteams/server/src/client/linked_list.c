/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** linked_list
*/

#include "../../include/main.h"

client_t *get_client_by_fd(client_t *list, int fd)
{
    client_t *tmp = list;

    while (tmp != NULL) {
        if (tmp->fd == fd)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}

client_t *add_node(client_t *list, int fd)
{
    client_t *tmp = list;

    if (list == NULL) {
        list = malloc(sizeof(client_t));
        fill_client(list, fd);
        return (list);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = malloc(sizeof(client_t));
    fill_client(tmp->next, fd);
    return (list);
}

client_t *remove_node(client_t *list, int fd_to_rm)
{
    client_t *tmp = list;
    client_t *prev = NULL;

    while (tmp) {
        maybe_remove(list, tmp, fd_to_rm, prev);
        prev = tmp;
        tmp = tmp->next;
    }
    return (list);
}

int count_nodes(client_t *list)
{
    int count = 0;
    client_t *tmp = list;

    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return (count);
}

void fill_client(client_t *node, int fd)
{
    node->fd = fd;
    node->username = NULL;
    node->password = NULL;
    node->is_logged = 0;
    node->location = NUL;
    node->location_uuid = NULL;
    node->uuid = NULL;
    node->next = NULL;
}
