/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** commands
*/

#include "../../include/main.h"

void exec_quit(int fd, datas_t *st, client_t *cl)
{
    (void)cl;
    printf("client with fd %d disconnected\n", fd);
    st->all_clients = remove_node(st->all_clients, fd);
    st->nb_clients = count_nodes(st->all_clients);
    printf("there are now %d client(s) connected\n", st->nb_clients);
    dprintf(fd, "221 Service closing control connection.\r\n");
    close(fd);
    FD_CLR(fd, &st->all_fd_clients);
}

void exec_noop(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    if (client->is_logged != 1) {
        dprintf(fd, "530 Not logged in.\r\n");
        return;
    }
    dprintf(fd, "200 Command okay.\r\n");
}

void exec_user(int fd, datas_t *st, client_t *client)
{
    (void)st;
    char **args = str_to_word_array(client->input);
    if (args[1] != NULL) {
        client->username = strdup(args[1]);
        printf("username: %s set to client %d\n", client->username,
                                                    client->fd);
        if (client->password == NULL ||
        strcmp(client->password, "") != 0) {
            dprintf(fd, "331 User name okay, need password.\r\n");
        } else {
            client->is_logged = true;
            dprintf(fd, "230 User logged in, proceed.\r\n");
        }
    }
    free_2d_array(args);
}

void exec_pass(int fd, datas_t *st, client_t *client)
{
    (void)st;
    char **args = str_to_word_array(client->input);

    client->password = args[1] == NULL ? "" : strdup(args[1]);
    printf("password: '%s' set to client %d\n", client->password, client->fd);
    if (client->username == NULL ||
    strcmp(client->username, "Anonymous") != 0) {
        dprintf(fd, "332 Need account for login.\r\n");
    } else {
        client->is_logged = true;
        dprintf(fd, "230 User logged in, proceed.\r\n");
        }
    free_2d_array(args);
}

void exec_cwd(int fd, datas_t *st, client_t *client)
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
    printf("args[1]: %s\n", args[1]);
    chdir(args[1]);
    client->path = strdup(getcwd(NULL, 0));
    chdir(st->serv->path);
    dprintf(fd, "250 Requested file action okay, completed.\r\n");
}
