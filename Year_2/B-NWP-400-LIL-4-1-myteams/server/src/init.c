/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** init
*/

#include "../include/main.h"

int init_datas(datas_t *datas, char **av)
{
    datas->nb_max_fd = 0;
    datas->nb_clients = 0;
    datas->serv = malloc(sizeof(serv_t));
    datas->serv->port = atoi(av[1]);
    datas->serv->path = strdup(getcwd(NULL, 0));
    chdir(av[2]);
    datas->serv->c_path = strdup(getcwd(NULL, 0));
    chdir("-");
    if (!datas->serv)
        return (84);
    datas->serv->sock_in = malloc(sizeof(struct sockaddr_in));
    datas->serv->sock_in->sin_family = AF_INET;
    datas->serv->sock_in->sin_port = htons(datas->serv->port);
    datas->serv->sock_in->sin_addr.s_addr = INADDR_ANY;
    FD_ZERO(&datas->all_fd_clients);
    FD_ZERO(&datas->tmp_fd_clients);
    datas->all_clients = NULL;
    datas->all_teams = NULL;
    return (0);
}

int init_socket(datas_t *datas)
{
    datas->serv->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (datas->serv->fd == -1) {
        printf("Error: can't create socket 2\n");
        return (84);
    }
    if (bind(datas->serv->fd, (struct sockaddr *)datas->serv->sock_in,
    sizeof(struct sockaddr_in)) == -1) {
        printf("Error: can't bind socket\n");
        return (84);
    }
    if (listen(datas->serv->fd, 5) == -1) {
        printf("Error: can't listen socket\n");
        return (84);
    }
    FD_SET(datas->serv->fd, &datas->all_fd_clients);
    datas->nb_max_fd = datas->serv->fd;
    return (0);
}
