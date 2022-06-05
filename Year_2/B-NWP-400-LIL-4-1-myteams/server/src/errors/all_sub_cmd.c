/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** all_sub_cmd
*/

#include "../../include/main.h"

bool is_error_subscribe(datas_t *st, client_t *client)
{
    char *target_uuid = str_tokenise_quoted(str_tokenise(client->input)[1])[0];
    if (!client->is_logged)
        return (true);
    return (false);
}

bool is_error_subscribed(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}

bool is_error_unsubscribe(datas_t *st, client_t *client)
{
    char *target_uuid = str_tokenise_quoted(str_tokenise(client->input)[1])[0];
    if (!client->is_logged)
        return (true);
    return (false);
}
