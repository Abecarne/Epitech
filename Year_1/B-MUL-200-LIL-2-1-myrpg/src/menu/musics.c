/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** musics
*/

#include "menu.h"

void music_menu(st_main_menu *st)
{
    sfMusic_stop(st->music->back);
    sfMusic_stop(st->music->fight);
    sfMusic_play(st->music->main);
    sfMusic_setLoop(st->music->main, sfTrue);
}

void music_game(st_main_menu *st)
{
    sfMusic_stop(st->music->fight);
    sfMusic_stop(st->music->main);
    sfMusic_play(st->music->back);
    sfMusic_setLoop(st->music->back, sfTrue);
}

void music_pause(st_main_menu *st)
{
    sfMusic_pause(st->music->back);
}