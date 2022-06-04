/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** store2
*/

#include "../../include/main.h"

void new_team_created(datas_t *st, char *buffer)
{
    (void)st;
    char *uuid = NULL;
    char *name = NULL;
    char *description = NULL;

    uuid = strtok(buffer, "¤");
    name = strtok(NULL, "¤");
    description = strtok(NULL, "¤");
    client_event_team_created(uuid, name, description);
}

void new_channel_created(datas_t *st, char *buffer)
{
    (void)st;
    char *uuid = NULL;
    char *name = NULL;
    char *description = NULL;

    uuid = strtok(buffer, "¤");
    name = strtok(NULL, "¤");
    description = strtok(NULL, "¤");
    client_event_channel_created(uuid, name, description);
}

void new_thread_created(datas_t *st, char *buffer)
{
    (void)st;
    client_error_unknown_user(buffer);
}

void new_reply_created(datas_t *st, char *buffer)
{
    (void)st;
    client_error_unknown_user(buffer);
}
