/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** create_cmd
*/

#include "../../include/main.h"

bool is_error_create(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}

void *get_something_from_uuid(char *uuid, team_t *team, int i)
{
    team_t *tmp = team;
    void *result;

    return (NULL);
}
