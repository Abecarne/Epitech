/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** event
*/

#include "include/defender.h"

void event_menu(st_def *st)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music.clic);
        sfMusic_play(st->music.clic);
    }
}

int event_game(st_def *st)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        st->win = 2;
        return (1);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music.clic);
        sfMusic_play(st->music.clic);
    }
    return (0);
}

void event_pause(st_def *st)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music.clic);
        sfMusic_play(st->music.clic);
    }
}

void event_end(st_def *st)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music.clic);
        sfMusic_play(st->music.clic);
    }
}

int event_option(st_def *st)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfMusic_stop(st->music.clic);
        sfMusic_play(st->music.clic);
    }
    return (0);
}
