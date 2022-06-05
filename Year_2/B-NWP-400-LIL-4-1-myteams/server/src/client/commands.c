/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** commands
*/

#include "../../include/main.h"

void switch_case_add(char **all_uuid, int n, datas_t *st, client_t *client)
{
    switch (get_uuid_type(all_uuid[n], st)) {
        case 1: client->location = TEAM;
            break;
        case 2: client->location = CHANNEL;
            break;
        case 3: client->location = THREAD;
            break;
        default: client->location = NUL;
            break;
    }
}

void exec_use(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    int n = 0;
    char **all_uuid = get_uuid(str_tokenise(client->input));
    bool error = valide_uuid(all_uuid, st, client, &n);

    if (error || n == 0) {
        dprintf(fd, "212 Context changed.\n");
        client->location_uuid = (n == 0) ? NULL : all_uuid[n];
        switch_case_add(all_uuid, n, st, client);
    } else
        dprintf(fd, "412 Error: Context change refused.\n");
}

void exec_user(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    bool error = is_error_user(client);
    char **tokens = str_tokenise_special(client->input);
    char **datas = fill_with_quoted(tokens);
    client_t *user = get_client_by_uuid(st, datas[0]);

    if (!error) {
        dprintf(fd, "INFOUSER:%s¤%s¤%d¤\n", user->uuid, user->username,
                                                        user->is_logged);
        usleep(5);
        dprintf(fd, "241 User infos.\n");
    } else {
        dprintf(fd, "441 Error: User not found.\n");
    }
    printf("Client dans user\n");
}

void exec_help(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;
    dprintf(fd, "111 HELP.\n");
}

void exec_list(int fd, datas_t *st, client_t *client)
{
    (void)st;
    (void)client;

    switch (client->location) {
        case NUL:
            case_of_nul2(st, client->fd, client);
            break;
        case TEAM:
            case_of_team2(st, client->fd, client);
            break;
        case CHANNEL:
            case_of_channel2(st, client->fd, client);
            break;
        case THREAD:
            case_of_thread2(st, client->fd, client);
            break;
    }
    printf("Client dans list\n");
}
