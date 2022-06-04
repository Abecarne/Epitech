/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** loops
*/

#include "include/defender.h"

int loop_menu(st_def *st)
{
    init_var(st);
    music_menu(st);
    while (sfRenderWindow_isOpen(st->data.wmain)) {
        while (sfRenderWindow_pollEvent(st->data.wmain, &st->data.event)) {
            if (st->data.event.type == sfEvtClosed) {
                    sfRenderWindow_close(st->data.wmain);
                    st->status = -1;
            }
            event_menu(st);
        }
        sc_menu(st);
        if (hover_menu(st) == 1)
            break;
    }
    return (0);
}

int loop_game(st_def *st)
{
    music_game(st);
    while (sfRenderWindow_isOpen(st->data.wmain)) {
        while (sfRenderWindow_pollEvent(st->data.wmain, &st->data.event)) {
            if (st->data.event.type == sfEvtClosed) {
                    sfRenderWindow_close(st->data.wmain);
                    st->status = -1;
            }
            if (event_game(st) == 1)
                return (1);
        }
        if (sc_game(st) == 1)
            break;
        if (hover_game(st) == 1)
            break;
        if (hover_pause_game(st, st->text.pause)== 1)
            break;
    }
    return (0);
}

int loop_pause(st_def *st)
{
    music_pause(st);
    while (sfRenderWindow_isOpen(st->data.wmain)) {
        while (sfRenderWindow_pollEvent(st->data.wmain, &st->data.event)) {
            if (st->data.event.type == sfEvtClosed) {
                    sfRenderWindow_close(st->data.wmain);
                    st->status = -1;
            }
            event_pause(st);
        }
        sc_pause(st);
        if (hover_pause(st) == 1)
            break;
    }
    return (0);
}

int loop_end(st_def *st)
{
    while (sfRenderWindow_isOpen(st->data.wmain)) {
        while (sfRenderWindow_pollEvent(st->data.wmain, &st->data.event)) {
            if (st->data.event.type == sfEvtClosed ||
                st->data.event.key.code == sfKeyEscape) {
                    sfRenderWindow_close(st->data.wmain);
                    st->status = -1;
            }
            event_end(st);
        }
        sc_end(st);
        if (hover_exit(st, st->spm.exit2) == 1)
            return (1);
    }
    return (0);
}

int loop_option(st_def *st)
{
    while (sfRenderWindow_isOpen(st->data.wmain)) {
        while (sfRenderWindow_pollEvent(st->data.wmain, &st->data.event)) {
            if (st->data.event.type == sfEvtClosed ||
                st->data.event.key.code == sfKeyEscape) {
                    sfRenderWindow_close(st->data.wmain);
                    st->status = -1;
            }
            if (event_option(st) == 1)
                return (1);
        }
        sc_option(st);
        if (hover_option(st) == 1)
            break;
    }
    return (0);
}
