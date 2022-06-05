/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** free_ressources
*/

#include "../include/main.h"

void free_server(serv_t *serv)
{
    free(serv->path);
    free(serv);
}

void free_clients(client_t *list)
{
    client_t *tmp = list;

    while (list != NULL) {
        tmp = list->next;
        free_client(list);
        list = tmp;
    }
}

void free_client(client_t *node)
{
    if (node->username != NULL)
        free(node->username);
    if (node->password != NULL)
        free(node->password);
    free(node);
}

void free_datas(datas_t *datas)
{
    free_server(datas->serv);
    free_clients(datas->all_clients);
    free(datas);
}

void free_2d_array(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        free(array[i]);
        i++;
    }
    free(array);
}
