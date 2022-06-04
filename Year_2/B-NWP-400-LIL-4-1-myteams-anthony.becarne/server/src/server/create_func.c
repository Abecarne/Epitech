/*
** EPITECH PROJECT, 2022
** B-NWP-400-LIL-4-1-myteams-anthony.becarne [WSL : Ubuntu]
** File description:
** create_func
*/

#include "../../include/teams.h"
#include "../../include/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <uuid/uuid.h>

void create_thread(thread_t **list, client_t *client, int fd, char **init)
{
    thread_t *new = malloc(sizeof(thread_t));
    char *uuid = generate_uuid();

    new->uuid = uuid;
    new->title = strdup(init[1]);
    new->description = strdup(init[2]);
    new->all_replies = NULL;
    new->next = *list;
    *list = new;
    dprintf(fd, "222 Thread created.\n");
    usleep(5);
    server_event_thread_created(client->location_uuid, new->uuid,
    client->uuid, new->title, new->description);
}

void create_reply(reply_t **list, client_t *client, int fd, char **init)
{
    reply_t *new = malloc(sizeof(reply_t));
    char *uuid = generate_uuid();

    new->next = *list;
    new->comment_body = strdup(init[1]);
    *list = new;
    dprintf(fd, "223 Reply created.\n");
    usleep(5);
}

void create_channel(channel_t **list, client_t *client, int fd, char **init)
{
    channel_t *new = malloc(sizeof(channel_t));
    char *uuid = generate_uuid();

    new->uuid = uuid;
    new->title = strdup(init[1]);
    new->description = strdup(init[2]);
    new->all_threads = NULL;
    new->next = *list;
    *list = new;
    dprintf(fd, "CHANNELCREATED:%s¤%s¤%s¤\n", new->uuid, new->title,
        new->description);
    usleep(5);
    server_event_channel_created(client->location_uuid, new->uuid,
                                                        new->title);
}

void create_teams(datas_t *st, client_t *client, int fd, char **init)
{
    team_t *new = malloc(sizeof(team_t));
    char *uuid = generate_uuid();

    new->uuid = uuid;
    new->users = NULL;
    new->title = strdup(init[1]);
    new->description = strdup(init[2]);
    new->all_channels = NULL;
    new->next = st->all_teams;
    st->all_teams = new;
    for (client_t *tmp = st->all_clients; tmp; tmp = tmp->next) {
        dprintf(tmp->fd, "TEAMCREATED:%s¤%s¤%s¤\n", new->uuid, new->title,
            new->description);
    }
    usleep(5);
    server_event_team_created(new->uuid, new->title,
        client->uuid);
}
