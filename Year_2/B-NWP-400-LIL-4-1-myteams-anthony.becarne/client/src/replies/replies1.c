/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** replies1
*/

#include "../../include/main.h"

void reply_110(datas_t *st)
{
    (void)st;
}

void reply_111(datas_t *st)
{
    (void)st;
    help1();
    help2();
    help3();
}

void reply_202(datas_t *st)
{
    (void)st;
    ask_to_serv(st, "UUID");
    ask_to_serv(st, "USERNAME");
    client_event_logged_in(st->client->uuid, st->client->username);
}

void reply_203(datas_t *st)
{
    (void)st;
    ask_to_serv(st, "UUID");
    ask_to_serv(st, "USERNAME");
    client_event_logged_out(st->client->uuid, st->client->username);
}

void reply_206(datas_t *st)
{
    (void)st;
}
