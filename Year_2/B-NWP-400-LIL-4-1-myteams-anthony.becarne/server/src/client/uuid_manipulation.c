/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL : Ubuntu]
** File description:
** uuid_manipulation
*/

#include "../../include/main.h"

char **get_uuid(char **arg)
{
    int n = 0;
    int i = 0;
    char **uuid = NULL;

    for (;arg[n] != NULL; n++);
    uuid = malloc(sizeof(char *) * (n + 1));
    for (; i < n; i++)
        uuid[i] = strdup(str_tokenise_quoted(arg[i])[0]);
    uuid[i] = NULL;
    return (uuid);
}

bool is_that_uuid(char *uuid, void *t, int i)
{
    thread_t *tmp_thread;
    team_t *tmp_team;
    channel_t *tmp_channel;
    bool y = false;

    if (i == 3) {
        tmp_thread = (thread_t *)t;
        for (; tmp_thread != NULL; tmp_thread = tmp_thread->next)
            y = (strcmp(tmp_thread->uuid,uuid) == 0) ? true : y;
    } else if (i == 2) {
        tmp_channel = (channel_t *)t;
        for (; tmp_channel != NULL; tmp_channel = tmp_channel->next)
            y = (strcmp(tmp_channel->uuid,uuid) == 0) ? true : y;
    } else {
        tmp_team = (team_t *)t;
        for (; tmp_team != NULL; tmp_team = tmp_team->next)
            y = (strcmp(tmp_team->uuid,uuid) == 0) ? true : y;
    }
    return (y);
}

int get_uuid_type(char *uuid, datas_t *st)
{
    team_t *tmp = st->all_teams;

    for (; tmp != NULL; tmp = tmp->next) {
        if (is_that_uuid(uuid, (void *)tmp, 1))
            return (1);
        if (tmp != NULL && is_that_uuid(uuid, (void *)tmp->all_channels, 2))
            return (2);
        if (tmp->all_channels != NULL &&
        is_that_uuid(uuid, (void *)tmp->all_channels->all_threads, 3))
            return (3);
    }
    return (84);
}

bool check_pos_uuid(int n, char **uuid, client_t *client, datas_t *st)
{
    return (false);
}

bool valide_uuid(char **uuid, datas_t *st, client_t *client, int *n)
{
    for (; uuid[*n] != NULL; *n += 1);
    *n -= 1;
    if (*n > 3)
        return (false);
    return (check_pos_uuid(*n, uuid, client, st));
}
