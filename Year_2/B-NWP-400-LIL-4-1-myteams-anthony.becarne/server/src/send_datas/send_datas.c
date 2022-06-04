/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** send_datas
*/

#include "../../include/main.h"

void send_uuid(int fd, datas_t *st, client_t *actual)
{
    (void)st;
    dprintf(fd, "UUID:%s\n", actual->uuid);
}

void send_username(int fd, datas_t *st, client_t *actual)
{
    (void)st;
    dprintf(fd, "USERNAME:%s\n", actual->username);
}
