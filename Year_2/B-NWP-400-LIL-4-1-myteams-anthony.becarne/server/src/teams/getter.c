/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** getter
*/

#include "../../include/main.h"

team_t *get_team_by_uuid(datas_t *st, char *uuid)
{
    team_t *team = st->all_teams;

    while (team) {
        if (strcmp(team->uuid, uuid) == 0)
            return (team);
        team = team->next;
    }
    return (NULL);
}

channel_t *get_channel_by_uuid(team_t *team, char *uuid)
{
    channel_t *channel = team->all_channels;

    while (channel) {
        if (strcmp(channel->uuid, uuid) == 0)
            return (channel);
        channel = channel->next;
    }
    return (NULL);
}

thread_t *get_thread_by_uuid(channel_t *channel, char *uuid)
{
    thread_t *thread = channel->all_threads;

    while (thread) {
        if (strcmp(thread->uuid, uuid) == 0)
            return (thread);
        thread = thread->next;
    }
    return (NULL);
}

client_t *get_client_by_uuid(datas_t *st, char *uuid)
{
    client_t *client = st->all_clients;

    while (client) {
        if (strcmp(client->uuid, uuid) == 0)
            return (client);
        client = client->next;
    }
    return (NULL);
}
