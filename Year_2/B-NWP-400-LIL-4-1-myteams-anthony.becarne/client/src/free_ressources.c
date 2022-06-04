/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** free_ressources
*/

#include "../include/main.h"

void free_client(client_t *serv)
{
    free(serv->path);
    free(serv);
}

void free_datas(datas_t *datas)
{
    free_client(datas->client);
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
