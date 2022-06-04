/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** commands2
*/

#include "../../include/main.h"

void exec_cdup(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    chdir(client->path);
    chdir("../");
    client->path = strdup(getcwd(NULL, 0));
    chdir(st->serv->path);
    dprintf(fd, "200 Command okay.\r\n");
}

void exec_dele(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    char **args = str_to_word_array(client->input);
    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    if (args[1] == NULL) {
        dprintf(fd, "501 Syntax error in parameters or arguments.\r\n");
        return;
    }
    chdir(client->path);
    remove(args[1]);
    chdir(st->serv->path);
    dprintf(fd, "250 Requested file action okay, completed.\r\n");
}

void exec_pwd(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    dprintf(fd, "257 \"%s\" created.\r\n", client->path);
}

void exec_pasv(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    dprintf(fd, "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n");
}

void exec_port(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    dprintf(fd, "200 Command okay.\r\n");
}
