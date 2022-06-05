/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** all_cases_in_switch
*/

#include "../../include/main.h"

void case_of_nul(datas_t *st, int fd, char **init, client_t *client)
{
    bool error = false;

    if (!error) {
        create_teams(st, client, fd, init);
        dprintf(fd, "220 Team created.\n");
    } else {
        dprintf(fd, "420 Error: Team creation refused.\n");
    }
}

void case_of_team(datas_t *st, int fd, char **init, client_t *client)
{
    bool error = false;

    if (!error) {
        create_channel(&((team_t *)get_something_from_uuid(
        client->location_uuid, st->all_teams, 1))->all_channels,
        client, fd, init);
        dprintf(fd, "221 Channel created.\n");
    } else {
        dprintf(fd, "421 Error: Channel creation refused.\n");
    }

}

void case_of_channel(datas_t *st, int fd, char **init, client_t *client)
{
    bool error = false;
    channel_t *tmp = (channel_t *)get_something_from_uuid(
                client->location_uuid, st->all_teams, 2);

    if (!error) {
        create_thread(&tmp->all_threads,
                client, fd, init);
        dprintf(fd, "222 Thread created.\n");
    } else {
        dprintf(fd, "422 Error: Thread creation refused.\n");
    }

}

void case_of_thread(datas_t *st, int fd, char **init, client_t *client)
{
    bool error = false;
    thread_t *tmp = (thread_t *)get_something_from_uuid(
                client->location_uuid, st->all_teams, 3);

    if (!error) {
        create_reply(&tmp->all_replies,
                client, fd, init);
        server_event_reply_created(tmp->uuid, client->uuid, init[1]);
        dprintf(fd, "223 Reply created.\n");
    } else {
        dprintf(fd, "423 Error: Reply creation refused.\n");
    }

}
