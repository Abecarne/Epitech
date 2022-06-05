/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** ask_to_serv
*/

#include "../../include/main.h"

void ask_to_serv(datas_t *st, char *message)
{
    char *buffer = malloc(sizeof(char) * 4096);
    int nb_read = 0;

    dprintf(st->client->fd, "%s", message);
    nb_read = read(st->client->fd, buffer, 4096);
    if (nb_read == -1) {
        perror("read");
        return;
    }
    buffer = remove_last_char(buffer);
    check_response_from_server(st, buffer);
    store_datas(st, buffer);
    free(buffer);
}
