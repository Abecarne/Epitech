/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** window_main_loop
*/

#include "menu.h"

int loop_menu_loop(st_main_menu *st)
{
    while (sfRenderWindow_pollEvent(st->data->wmain, &st->data->event))
        if (event_menu(st) == 1)
            return (1);
    return (0);
}

int loop_game_loop(st_main_menu *st)
{
    while (sfRenderWindow_pollEvent(st->data->wmain, &st->data->event))
        if (event_game(st) == 1)
            return (1);
    return (0);
}

int loop_pause_loop(st_main_menu *st)
{
    while (sfRenderWindow_pollEvent(st->data->wmain, &st->data->event))
        if (event_pause(st) == 1)
            return (1);
    return (0);
}

int loop_option_loop(st_main_menu *st)
{
    while (sfRenderWindow_pollEvent(st->data->wmain, &st->data->event))
        if (event_option(st) == 1)
            return (1);
    return (0);
}

int loop_end_loop(st_main_menu *st)
{
    while (sfRenderWindow_pollEvent(st->data->wmain, &st->data->event))
        if (event_end(st) == 1)
            return (1);
    return (0);
}
