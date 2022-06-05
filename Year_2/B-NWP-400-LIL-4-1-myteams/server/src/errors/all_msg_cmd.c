/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** all_msg_cmd
*/

#include "../../include/main.h"

bool is_error_send(datas_t *st, client_t *client)
{
    char **tokens = str_tokenise_special(client->input);
    char **datas = fill_with_quoted(tokens++);

    if (is_uuid_in_users(st, datas[0]) == false) {
        dprintf(client->fd, "WRONGUSERUUID:%s\n", datas[0]);
        return (true);
    }
    if (client->is_logged == false)
        return (true);
    return (false);
}

bool is_error_messages(client_t *client)
{
    if (client->is_logged == false)
        return (true);
    return (false);
}
