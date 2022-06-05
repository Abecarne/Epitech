/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** init
*/

#include "../include/main.h"

int init_datas(datas_t *datas, char **av)
{
    datas->client = malloc(sizeof(client_t));
    if (!datas->client)
        return (84);
    datas->client->ip = strdup(av[1]);
    datas->client->port = atoi(av[2]);
    datas->client->path = strdup(getcwd(NULL, 0));
    chdir(av[2]);
    datas->client->current_dir = strdup(getcwd(NULL, 0));
    chdir("-");
    datas->client->sock_in = malloc(sizeof(struct sockaddr_in));
    datas->client->sock_in->sin_family = AF_INET;
    datas->client->sock_in->sin_port = htons(datas->client->port);
    datas->client->sock_in->sin_addr.s_addr = inet_addr(datas->client->ip);
    return (0);
}

int init_socket(datas_t *datas)
{
    datas->client->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (datas->client->fd == -1) {
        printf("Error: can't create socket\n");
        return (84);
    }
    if (inet_pton(AF_INET, datas->client->ip,
        &datas->client->sock_in->sin_addr) <= 0) {
        printf("Invalid address\n");
        return (-1);
    }
    if (connect(datas->client->fd, (struct sockaddr*)datas->client->sock_in,
        sizeof(struct sockaddr_in)) < 0) {
        printf("%s\n", strerror(errno));
        return (-1);
    }
    FD_SET(datas->client->fd, &datas->my_fd);
    datas->max_fd = datas->client->fd;
    return (0);
}
