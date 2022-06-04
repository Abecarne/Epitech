/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** store1
*/

#include "../../include/main.h"

void store_uuid(datas_t *st, char *buffer)
{
    (void)st;
    if (st->client->uuid)
        free(st->client->uuid);
    st->client->uuid = strdup(buffer);
}

void store_username(datas_t *st, char *buffer)
{
    (void)st;
    if (st->client->username)
        free(st->client->username);
    st->client->username = strdup(buffer);
}

void wrong_user_uuid(datas_t *st, char *buffer)
{
    (void)st;
    client_error_unknown_user(buffer);
}

void store_new_message(datas_t *st, char *buffer)
{
    (void)st;
    char *msg = NULL;
    char *correspondant = NULL;

    msg = strtok(buffer, "¤");
    if (msg == NULL)
        return;
    correspondant = strtok(NULL, "¤");
    client_event_private_message_received(correspondant, msg);
}

void print_all_users(datas_t *st, char *buffer)
{
    (void)st;
    char *uuid = NULL;
    char *username = NULL;
    int is_logged = 0;

    uuid = strtok(buffer, "¤");
    if (uuid == NULL)
        return;
    username = strtok(NULL, "¤");
    if (username == NULL)
        return;
    is_logged = atoi(strtok(NULL, "¤"));
    client_print_users(uuid, username, is_logged);
}
