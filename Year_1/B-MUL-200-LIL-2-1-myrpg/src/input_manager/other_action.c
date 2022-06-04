/*
** EPITECH PROJECT, 2021
** other_action.c
** File description:
** other_action
*/

#include "my.h"
#include "framing_engine.h"

void next_lvl(int x, int y, int lvl, framing *lvl)
{
    lvl->player_y = y;
    lvl->player_x = x;
    lvl->next = lvl;
}

void other_action(framing *lvl, int x, int y)
{
    if (lvl->map[y][x] == 'O' && y == 0 && lvl->selected_map == 0 && y == 0)
        next_lvl(24, 47, 1);
    if (lvl->map[y][x] == 'O' && y == 0 && lvl->selected_map == 1 && y == 47)
        next_lvl(19, 0, 0);
}
