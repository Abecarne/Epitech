/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main_server
*/

#include "../include/main.h"

char *get_command(void)
{
    char *buffer = malloc(sizeof(char) * 4096);
    size_t size = 0;
    ssize_t input;

    if ((input = getline(&buffer, &size, stdin)) == -1)
        return (NULL);
    buffer = remove_last_char(buffer);
    return (buffer);
}

char *read_command(int fd)
{
    char *buffer = malloc(sizeof(char) * 4096);
    int nb_read = 0;

    nb_read = read(fd, buffer, 4096);
    if (nb_read == -1) {
        perror("read");
        return (NULL);
    }
    remove_last_char(buffer);
    return (buffer);
}

int server_manager(datas_t *st)
{
    if (FD_ISSET(st->client->fd, &st->my_fd)) {
        if (is_closed(st->client->fd) == 1)
            return (84);
        char *buffer = NULL;
        buffer = read_command(st->client->fd);
        check_response_from_server(st, buffer);
        store_datas(st, buffer);
        free(buffer);
    } else {
        char *buffer = get_command();
        if (buffer == NULL)
            return (84);
        dprintf(st->client->fd, "%s", buffer);
    }
    return (0);
}

int selection(datas_t *st)
{
    struct timeval time = {0, 1};

    int retval_select = select(st->max_fd + 1, &st->my_fd, NULL, NULL, &time);
    if (retval_select == -1) {
        perror("select");
        return (84);
    }
    if (retval_select == 0)
        return (0);
    if (server_manager(st) == 84)
        return (84);
    return (0);
}

int server_ftp(datas_t *st)
{
    if (init_socket(st) == 84) {
        printf("Error: can't create socket\n");
        return (84);
    }
    if (st->client->fd == 84)
        return (84);
    while (1) {
        update_set_fd(st);
        if (selection(st) == 84) {
            printf("End Of Client Instance. Goodbye!\n");
            return (84);
        }
    }
    return (0);
}
