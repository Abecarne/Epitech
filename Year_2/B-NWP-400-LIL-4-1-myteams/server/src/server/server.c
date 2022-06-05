/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** server
*/

#include "../../include/main.h"

char *generate_uuid(void)
{
    uuid_t binuuid;
    char *uuid = malloc(37);

    uuid_generate_random(binuuid);
    uuid_unparse_upper(binuuid, uuid);
    return (uuid);
}

int accept_connection(datas_t *st)
{
    int client_fd;
    char *uuid;
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    client_fd = accept(st->serv->fd, (struct sockaddr *)&client_address,
        &client_address_size);
    if (client_fd == -1) {
        perror("accept");
        return (-1);
    }
    st->all_clients = add_node(st->all_clients, client_fd);
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
    buffer[nb_read] = '\0';
    return (buffer);
}
