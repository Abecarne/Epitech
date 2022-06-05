/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** add_users
*/

#include "../../include/main.h"

void add_user_to_team(team_t *team, datas_t *st, client_t *client)
{
    user_t *user = malloc(sizeof(user_t));
    user->uuid = strdup(client->uuid);
    user->username = strdup(client->username);
    user->is_logged = true;
    user->next = NULL;
    if (team->users == NULL) {
        team->users = user;
    } else {
        user_t *tmp = team->users;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = user;
    }
    printf("%s has been added to team %s\n", client->username, team->title);
    dprintf(client->fd, "SUBSCRIBEDTOTEAM:%s¤%s¤\n", client->uuid, team->uuid);
}
