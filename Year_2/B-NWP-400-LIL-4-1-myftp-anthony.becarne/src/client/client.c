/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** client
*/

#include "../../include/main.h"

static void *command_tab[][2] = {
    {"QUIT\r\n", exec_quit}, {"NOOP\r\n", exec_noop}, {"USER", exec_user},
    {"PASS", exec_pass}, {"CWD", exec_cwd}, {"CDUP\r\n", exec_cdup},
    {"DELE", exec_dele}, {"PWD\r\n", exec_pwd}, {"PASV\r\n", exec_pasv},
    {"PORT", exec_port}, {"HELP", exec_help}, {"RETR", exec_retr},
    {"STOR", exec_stor}, {"LIST", exec_list}, {NULL, NULL}
};

void command_manager(int fd, datas_t *st, client_t *actual)
{
    for (int i = 0; command_tab[i][0]; i++) {
        if (strncmp(actual->input, (char *)command_tab[i][0],
        strlen((char *)command_tab[i][0])) == 0) {
            ((command)command_tab[i][1])(fd, st, actual);
            return;
        }
    }
    dprintf(fd, "500 Syntax error, command unrecognized.\r\n");
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
