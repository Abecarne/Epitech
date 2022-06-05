/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL : Debian]
** File description:
** all_cases_in_switch2
*/

#include "../../include/main.h"

void case_of_nul2(datas_t *st, int fd, client_t *client)
{
    bool error = false;

    if (!error)
        show_teams(fd, st->all_teams);
    else
        dprintf(fd, "435 Error: Existing teams not listed.\n");
}

void case_of_team2(datas_t *st, int fd, client_t *client)
{
    team_t *tmp = (team_t *)get_something_from_uuid(client->location_uuid,
    st->all_teams, 1);
    bool error = false;

    if (!error)
        show_channels(fd, tmp->all_channels);
    else
        dprintf(fd, "436 Error: Existing channels not listed.\n");
}

void case_of_channel2(datas_t *st, int fd, client_t *client)
{
    channel_t *tmp = (channel_t *)get_something_from_uuid(
        client->location_uuid, st->all_teams, 2);
    bool error = false;

    if (!error)
        show_threads(fd, tmp->all_threads);
    else
        dprintf(fd, "437 Error: Existing threads not listed.\n");
}

void case_of_thread2(datas_t *st, int fd, client_t *client)
{
    thread_t *tmp = (thread_t *)get_something_from_uuid(client->location_uuid,
    st->all_teams, 3);
    bool error = false;

    if (!error)
        show_replies(fd, tmp->all_replies);
    else
        dprintf(fd, "438 Error: Existing replies not listed.\n");

}
