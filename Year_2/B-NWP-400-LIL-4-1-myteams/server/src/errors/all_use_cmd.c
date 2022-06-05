/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** errors1
*/

#include "../../include/main.h"

bool is_error_use(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}

bool is_error_user(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}

bool is_error_users(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}
