/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** store3
*/

#include "../../include/main.h"

void print_infos_user(datas_t *st, char *buffer)
{
    (void)st;
    char *uuid = NULL;
    char *username = NULL;
    int is_logged = 0;

    uuid = strtok(buffer, "¤");
    username = strtok(NULL, "¤");
    is_logged = atoi(strtok(NULL, "¤"));
    client_print_user(uuid, username, is_logged);
}

void team_subscription(datas_t *st, char *buffer)
{
    (void)st;
    char *user_uuid = NULL;
    char *team_uuid = NULL;

    user_uuid = strtok(buffer, "¤");
    team_uuid = strtok(NULL, "¤");
    client_print_subscribed(user_uuid, team_uuid);
}
