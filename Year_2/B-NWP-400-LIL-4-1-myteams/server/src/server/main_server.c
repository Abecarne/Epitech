/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main_server
*/

#include "../../include/main.h"

int server_manager(datas_t *st)
{
    if (FD_ISSET(st->serv->fd, &st->tmp_fd_clients)) {
        int client_fd = accept_connection(st);
        if (client_fd == -1)
            return (84);
        FD_SET(client_fd, &st->all_fd_clients);
        if (client_fd > st->nb_max_fd)
            st->nb_max_fd = client_fd;
        printf("new client connected with fd = %d\n", client_fd);
        st->nb_clients = count_nodes(st->all_clients);
        printf("total: %d clients connected\n", st->nb_clients);
        dprintf(client_fd, "110 Connection Establishment.\n");
    }
    return (0);
}

int selection(datas_t *st)
{
    if (select(st->nb_max_fd + 1, &st->tmp_fd_clients, NULL, NULL, NULL)) {
        if (server_manager(st) == 84)
            return (84);
        if (client_manager(st) == 84)
            return (84);
    }
    return (0);
}

int server_ftp(datas_t *st)
{
    if (init_socket(st) == 84) {
        printf("Error: can't create socket\n");
        return (84);
    }
    if (st->serv->fd == 84)
        return (84);
    while (1) {
        st->tmp_fd_clients = st->all_fd_clients;
        if (selection(st) == 84)
            return (84);
    }
    return (0);
}
