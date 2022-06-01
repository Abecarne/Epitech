/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-dante-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** movement
*/

#include "../include/generator.h"

void set_start(st_generator *st)
{
    st->map[0][0] = 0;
    st->map[st->height - 1][st->width - 1] = 0;
}

void move_to_next(st_generator *st)
{
    st->map[st->y1][st->x1] = 0;
    st->map[st->y2][st->x2] = 0;
    st->x = st->x2;
    st->y = st->y2;
}

int check_movement(st_generator *st)
{
    st->x1 = st->x + st->dx;
    st->y1 = st->y + st->dy;
    st->x2 = st->x1 + st->dx;
    st->y2 = st->y1 + st->dy;
    if (st->x2 >= 0 && st->x2 < st->width && st->y2 >= 0 &&
        st->y2 < st->height)
        if (st->map[st->y1][st->x1] == 1 && st->map[st->y2][st->x2] == 1)
            return (1);
    return (0);
}