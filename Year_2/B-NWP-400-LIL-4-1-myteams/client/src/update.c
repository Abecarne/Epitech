/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** update
*/

#include "../include/main.h"
#include <sys/ioctl.h>

void update_set_fd(datas_t *st)
{
    FD_ZERO(&st->my_fd);
    FD_SET(0, &st->my_fd);
    FD_SET(st->client->fd, &st->my_fd);
}

bool is_closed(int sock)
{
    int n = 0;
    fd_set read_fds;
    struct timeval tv = {0, 0};

    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);
    select(sock + 1, &read_fds, 0, 0, &tv);
    if (!FD_ISSET(sock, &read_fds))
        return (false);
    ioctl(sock, FIONREAD, &n);
    return (n == 0);
}
