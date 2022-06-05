/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** commands3
*/

#include "../../include/main.h"

void exec_create(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    char **init = get_uuid(str_tokenise(client->input));

    switch (client->location) {
        case NUL:
            case_of_nul(st, fd, init, client);
            break;
        case TEAM:
            case_of_team(st, fd, init, client);
            break;
        case CHANNEL:
            case_of_channel(st, fd, init, client);
            break;
        case THREAD:
            case_of_thread(st, fd, init, client);
            break;
    }
}

void exec_messages(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = false;

    if (!error) {
        dprintf(fd, "232 Messages list.\n");
    } else {
        dprintf(fd, "432 Error: Messages not listed.\n");
    }
    printf("Client dans messages\n");
}

void exec_subscribe(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = is_error_subscribe(st, client);
    char *target_uuid = str_tokenise_quoted(str_tokenise(client->input)[1])[0];
    team_t *team = get_team_by_uuid(st, target_uuid);

    if (!error) {
        add_user_to_team(team, st, client);
        dprintf(fd, "208 Subscribed to team.\n");
    } else {
        dprintf(fd, "408 Error: Subscription refused.\n");
    }
}

void exec_subscribed(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = is_error_subscribed(client);

    if (!error) {
        dprintf(fd, "233 Subscribed teams list.\n");
    } else {
        dprintf(fd, "433 Error: Subscribed teams not listed.\n");
    }
    printf("Client dans subscribed\n");
}

void exec_unsubscribe(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = is_error_unsubscribe(st, client);

    if (!error) {
        dprintf(fd, "211 Unsubscribed from team.\n");
    } else {
        dprintf(fd, "411 Error: Unsubscription refused.\n");
    }
    printf("Client dans unsubscribe\n");
}
