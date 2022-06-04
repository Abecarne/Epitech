/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** music
*/

#include "include/defender.h"

void music_menu(st_def *st)
{
    sfMusic_stop(st->music.main_menu);
    sfMusic_play(st->music.main_menu);
    sfMusic_setLoop(st->music.main_menu, sfTrue);
}

void music_game(st_def *st)
{
    sfMusic_stop(st->music.main_menu);
    sfMusic_play(st->music.stage);
    sfMusic_setLoop(st->music.stage, sfTrue);
}

void music_pause(st_def *st)
{
    sfMusic_pause(st->music.stage);
}