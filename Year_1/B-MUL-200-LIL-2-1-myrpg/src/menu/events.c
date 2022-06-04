/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** events
*/

#include "menu.h"

int event_menu(st_main_menu *st)
{
    if (st->data->event.type == sfEvtClosed) {
        sfRenderWindow_close(st->data->wmain);
        st->status = -1;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music->clic);
        sfMusic_play(st->music->clic);
    }
    return (0);
}

int event_game(st_main_menu *st)
{
    if (st->data->event.type == sfEvtClosed) {
        sfRenderWindow_close(st->data->wmain);
        st->status = -1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        st->sc = 2;
        return (1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music->clic);
        sfMusic_play(st->music->clic);
    }
    if (enemi_inbound(st) == 0) {
        st->sc = 5;
        return (1);
    }
    return (0);
}

int event_pause(st_main_menu *st)
{
    if (st->data->event.type == sfEvtClosed) {
        sfRenderWindow_close(st->data->wmain);
        st->status = -1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        st->sc = 2;
        return (1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music->clic);
        sfMusic_play(st->music->clic);
    }
    return (0);
}

int event_option(st_main_menu *st)
{
    if (st->data->event.type == sfEvtClosed) {
        sfRenderWindow_close(st->data->wmain);
        st->status = -1;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music->clic);
        sfMusic_play(st->music->clic);
    }
    return (0);
}

int event_end(st_main_menu *st)
{
    if (st->data->event.type == sfEvtClosed ||
        st->data->event.key.code == sfKeyEscape) {
        sfRenderWindow_close(st->data->wmain);
        st->status = -1;
        return (1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music->clic);
        sfMusic_play(st->music->clic);
    }
    return (0);
}
