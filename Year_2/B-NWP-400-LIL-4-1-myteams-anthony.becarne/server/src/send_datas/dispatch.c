/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** dispatch
*/

#include "../../include/main.h"

static void *send_commands[][2] = {
    {"UUID", send_uuid},
    {"USERNAME", send_username},
    {NULL, NULL}
};

void dispatch_send(int fd, datas_t *st, client_t *actual)
{
    for (int i = 0; send_commands[i][0]; i++) {
        if (strcmp(actual->input, (char *)send_commands[i][0]) == 0) {
            ((command)send_commands[i][1])(fd, st, actual);
            return;
        }
    }
    dprintf(fd, "500 Syntax error, command unrecognized.");
}
