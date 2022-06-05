/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** infos_cmd
*/

#include "../../include/main.h"

bool is_error_list(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}

bool is_error_info(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}
