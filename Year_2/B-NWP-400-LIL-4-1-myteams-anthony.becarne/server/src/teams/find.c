/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** find
*/

#include "../../include/main.h"

bool is_uuid_in_teams(datas_t *st, char *target_uuid)
{
    for (struct team_s *tmp = st->all_teams; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->uuid, target_uuid) == 0)
            return (true);
    }
    return (false);
}

bool is_uuid_in_users(datas_t *st, char *target_uuid)
{
    for (client_t *tmp = st->all_clients; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->uuid, target_uuid) == 0)
            return (true);
    }
    return (false);
}
