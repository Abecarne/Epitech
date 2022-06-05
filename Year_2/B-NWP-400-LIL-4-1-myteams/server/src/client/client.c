/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** client
*/

#include "../../include/main.h"

static void *command_tab[][2] = {
    {"^[ |\t]*/users[ |\t]*$", exec_users},
    {"^[ |\t]*/user[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_user},
    {"^[ |\t]*/use[ |\t]*$", exec_use},
    {"^[ |\t]*/use[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_use},
    {"^[ |\t]*/use[ |\t]{1,}\".{1,}\"[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_use},
    {"^[ |\t]*/use[ |\t]{1,}\".{1,}\"[ |\t]{1,}\".{1,}\"[ |\t]{1,}\".{1,}\"\
                                                        [ |\t]*$", exec_use},
    {"^[ |\t]*/help[ |\t]*$", exec_help},
    {"^[ |\t]*/list[ |\t]*$", exec_list},
    {"^[ |\t]*/info[ |\t]*$", exec_info},
    {"^[ |\t]*/logout[ |\t]*$", exec_logout},
    {"^[ |\t]*/create[ |\t]*.*$", exec_create},
    {"^[ |\t]*/login[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_login},
    {"^[ |\t]*/create[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_create},
    {"^[ |\t]*/messages[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_messages},
    {"^[ |\t]*/subscribe[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_subscribe},
    {"^[ |\t]*/subscribed[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_subscribed},
    {"^[ |\t]*/unsubscribe[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_unsubscribe},
    {"^[ |\t]*/send[ |\t]{1,}\".{1,}\"[ |\t]{1,}\".{1,}\"[ |\t]*$", exec_send},
    {"^[ |\t]*/create[ |\t]{1,}\".{1,}\"[ |\t]*\".{1,}\"[ |\t]*$",
                                                                exec_create},
    {NULL, NULL}
};

void command_manager(int fd, datas_t *st, client_t *actual)
{
    printf("Le client %d a écrit: '%s'\n", fd, actual->input);
    for (int i = 0; command_tab[i][0]; i++) {
        if (regex_match(actual->input, (char *)command_tab[i][0],
        strlen((char *)command_tab[i][0])) == 0) {
            ((command)command_tab[i][1])(fd, st, actual);
            usleep(5);
            return;
        }
    }
    dispatch_send(fd, st, actual);
}

int move_client(datas_t *st, client_t *tmp, client_t *actual)
{
    if (FD_ISSET(tmp->fd, &st->tmp_fd_clients)) {
        actual = get_client_by_fd(st->all_clients, tmp->fd);
        actual->input = read_client(actual->fd);
        if (actual->input == NULL)
            return (84);
        command_manager(actual->fd, st, actual);
    }
    return (0);
}

int client_manager(datas_t *st)
{
    client_t *tmp = st->all_clients;
    client_t *actual = NULL;

    while (tmp != NULL) {
        if (move_client(st, tmp, actual) == 84)
            return (84);
        tmp = tmp->next;
    }
    return (0);
}
