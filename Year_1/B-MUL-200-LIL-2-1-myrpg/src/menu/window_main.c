/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** window_main
*/

#include "menu.h"

int loop_menu(st_main_menu *st)
{
    music_menu(st);
    while (sfRenderWindow_isOpen(st->data->wmain)) {
        if (loop_menu_loop(st) == 1)
            return (1);
        scene_menu(st);
        if (hover_menu(st) == 1)
            break;
    }
    return (0);
}

int loop_game(st_main_menu *st)
{
    music_game(st);
    while (sfRenderWindow_isOpen(st->data->wmain)) {
        if (loop_game_loop(st) == 1)
            return (1);
        scene_game(st);
    }
    return (0);
}

int loop_pause(st_main_menu *st)
{
    music_pause(st);
    while (sfRenderWindow_isOpen(st->data->wmain)) {
        if (loop_pause_loop(st) == 1)
            return (1);
        scene_pause(st);
        if (hover_pause(st) == 1)
            break;
    }
    return (0);
}

int loop_option(st_main_menu *st)
{
    while (sfRenderWindow_isOpen(st->data->wmain)) {
        if (loop_option_loop(st) == 1)
            return (1);
        scene_option(st);
        if (hover_option(st) == 1)
            break;
    }
    return (0);
}

int loop_end(st_main_menu *st)
{
    while (sfRenderWindow_isOpen(st->data->wmain)) {
        if (loop_end_loop(st) == 1)
            return (1);
        scene_end(st);
    }
    return (0);
}