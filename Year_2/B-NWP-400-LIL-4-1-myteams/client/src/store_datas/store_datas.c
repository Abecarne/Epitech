/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** store_datas
*/

#include "../../include/main.h"

static void *to_store[][2] = {
    {"UUID", store_uuid},
    {"USERNAME", store_username},
    {"WRONGUSERUUID", wrong_user_uuid},
    {"MSGRECEIVED", store_new_message},
    {"PRINTUSERS", print_all_users},
    {"TEAMCREATED", new_team_created},
    {"CHANNELCREATED", new_channel_created},
    {"INFOUSER", print_infos_user},
    {"SUBSCRIBEDTOTEAM", team_subscription},
    {NULL, NULL}
};

void store_datas(datas_t *st, char *buffer)
{
    char *token = NULL;
    char *saveptr = NULL;

    token = strtok_r(buffer, ":", &saveptr);
    if (token == NULL)
        return;
    for (int i = 0; to_store[i][0]; i++) {
        if (strcmp(token, to_store[i][0]) == 0) {
            ((store)to_store[i][1])(st, saveptr);
            return;
        }
    }
}
