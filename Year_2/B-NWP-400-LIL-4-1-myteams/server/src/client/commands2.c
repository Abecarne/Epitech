/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** commands2
*/

#include "../../include/main.h"

void exec_info(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = false;

    if (!error) {
        dprintf(fd, "242 Logged Users infos.\n");
    } else {
        dprintf(fd, "442 Error: Logged users not found.\n");
    }
    printf("Client dans info\n");
}

void exec_send(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = false;
    char **tokens = str_tokenise_special(client->input);
    char **datas = fill_with_quoted(tokens);
    client_t *user = get_client_by_uuid(st, datas[0]);

    error = is_error_send(st, client);
    if (!error) {
        dprintf(user->fd, "MSGRECEIVED:%s¤%s¤\n", datas[2], client->uuid);
        usleep(10);
        server_event_private_message_sended(client->uuid, user->uuid,
        datas[2]);
        usleep(10);
        dprintf(fd, "206 Message sent correctly.\n");
    } else {
        dprintf(fd, "406 Error: Message not sent.\n");
    }
}

void exec_users(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = is_error_users(client);

    if (!error) {
        client_t *tmp = st->all_clients;
        for (; tmp; tmp = tmp->next) {
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("UUID: %s\n", tmp->uuid);
            printf("USERNAME: %s\n", tmp->username);
            printf("ISLOGGED: %d\n", tmp->is_logged);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            dprintf(fd, "PRINTUSERS:%s¤%s¤%d\n", tmp->uuid, tmp->username,
            tmp->is_logged);
        }
        dprintf(fd, "231 Users list.\n");
    } else {
        dprintf(fd, "431 Error: Users list not found.\n");
    }
}

void exec_login(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = false;
    char **tokens = str_tokenise(client->input);

    client->username = strdup(str_tokenise_quoted(tokens[1])[0]);
    if (!error) {
        client->is_logged = true;
        client->uuid = generate_uuid();
        dprintf(fd, "202 Login accepted.\n");
        server_event_user_logged_in(client->uuid);
        server_event_user_created(client->uuid, client->username);
    } else {
        dprintf(fd, "402 Error: Login refused.\n");
    }
}

void exec_logout(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = is_error_logout(client);

    if (!error) {
        client->is_logged = false;
        dprintf(fd, "203 Logout accepted.\n");
        server_event_user_logged_out(client->uuid);
    } else {
        dprintf(fd, "403 Error: Logout refused.\n");
    }
}
