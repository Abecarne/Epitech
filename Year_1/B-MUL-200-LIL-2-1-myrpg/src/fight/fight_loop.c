/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fight_loop
*/

#include "menu.h"

void music_fight(st_main_menu *st)
{
    sfMusic_stop(st->music->back);
    sfMusic_stop(st->music->main);
    sfMusic_play(st->music->fight);
    sfMusic_setLoop(st->music->fight, sfTrue);
}

int event_fight(st_main_menu *st)
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

int event_attack(st_main_menu *st)
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

int loop_fight(st_main_menu *st)
{
    music_fight(st);
    while (sfRenderWindow_isOpen(st->data->wmain)) {
        if (loop_fight_loop(st) == 1)
            return (1);
        scene_fight(st);
        if (hover_fight(st) == 1)
            break;
    }
    return (0);
}

int loop_attack(st_main_menu *st)
{
    while (sfRenderWindow_isOpen(st->data->wmain)) {
        if (loop_attack_loop(st) == 1)
            return (1);
        scene_attack(st);
        if (hover_select_attack(st) == 1)
            break;
    }
    return (0);
}