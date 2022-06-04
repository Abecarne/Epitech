/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL : Ubuntu]
** File description:
** show_func
*/

#include "../../include/teams.h"
#include <stdio.h>
#include <stdlib.h>

void show_teams(int client_fd, team_t *teams)
{
    team_t *tmp = teams;

    for (;tmp->next != NULL; tmp = tmp->next) {
        dprintf(client_fd, "%s\n", tmp->uuid);
    }
    dprintf(client_fd, "238 Existing teams list.");
}

void show_channels(int client_fd, channel_t *channels)
{
    channel_t *tmp = channels;

    for (;tmp->next != NULL; tmp = tmp->next) {
        dprintf(client_fd, "%s\n", tmp->uuid);
    }
    dprintf(client_fd, "238 Existing channels list.");
}

void show_threads(int client_fd, thread_t *threads)
{
    thread_t *tmp = threads;

    for (;tmp != NULL; tmp = tmp->next) {
        dprintf(client_fd, "%s\n", tmp->uuid);
    }
    dprintf(client_fd, "238 Existing threads list.");
}

void show_users(int client_fd, user_t *user)
{
    user_t *tmp = user;

    for (;tmp != NULL; tmp = tmp->next) {
        dprintf(client_fd, "%s\n", tmp->uuid);
    }
}

void show_replies(int client_fd, reply_t *replies)
{
    reply_t *tmp = replies;

    for (; tmp != NULL; tmp = tmp->next) {
        dprintf(client_fd, "%s\n", tmp->message);
    }
    dprintf(client_fd, "238 Existing replies list.");
}
