/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** all_log_cmd
*/

#include "../../include/main.h"

bool is_error_login(client_t *client)
{
    return (false);
}

bool is_error_logout(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}
