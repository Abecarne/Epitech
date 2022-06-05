/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** server
*/

#include "../../include/main.h"

int accept_connection(int socket_fd)
{
    int client_fd;
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    client_fd = accept(socket_fd, (struct sockaddr *)&client_address,
                                                &client_address_size);
    if (client_fd == -1) {
        perror("accept");
        return (-1);
    }
    return (client_fd);
}

char *read_client(int client_fd)
{
    char *buffer = malloc(sizeof(char) * 4096);
    int nb_read = 0;

    nb_read = read(client_fd, buffer, 4096);
    if (nb_read == -1) {
        perror("read");
        return (NULL);
    }
    return (buffer);
}

int close_connection(int client_fd)
{
    if (close(client_fd) == -1) {
        perror("close");
        return (-1);
    }
    return (0);
}
