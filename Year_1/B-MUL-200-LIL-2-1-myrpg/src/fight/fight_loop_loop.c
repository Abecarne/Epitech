/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fight_loop_loop
*/

#include "menu.h"

int loop_fight_loop(st_main_menu *st)
{
    while (sfRenderWindow_pollEvent(st->data->wmain, &st->data->event))
        if (event_fight(st) == 1)
            return (1);
    return (0);
}

int loop_attack_loop(st_main_menu *st)
{
    while (sfRenderWindow_pollEvent(st->data->wmain, &st->data->event))
        if (event_attack(st) == 1)
            return (1);
    return (0);
}