/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** generator
*/

#include "../include/generator.h"

void get_direction(st_generator *st, int dir)
{
    st->dx = 0;
    st->dy = 0;
    switch (dir) {
        case 0:
            st->dx = 1;
            break;
        case 1:
            st->dy = 1;
            break;
        case 2:
            st->dx = -1;
            break;
        default:
            st->dy = -1;
            break;
    }
}

void dig_hole(st_generator *st)
{
    int dir = 0;
    int cpt = 0;

    dir = rand() % 4;
    while (cpt < 4) {
        get_direction(st, dir);
        if (check_movement(st) == 1) {
            dir = rand() % 4;
            cpt = 0;
            st->map[st->y1][st->x1] = 0;
            st->map[st->y2][st->x2] = 0;
            st->x = st->x2;
            st->y = st->y2;
        } else {
            dir = (dir + 1) % 4;
            cpt++;
        }
    }
}

void generator(st_generator *st, int width, int height)
{
    for (st->y = 0; st->y < height; st->y += 2) {
        for (st->x = 0; st->x < width; st->x += 2) {
            dig_hole(st);
        }
    }
}

void maze(st_generator *st)
{
    srand(time(NULL));
    st->map = malloc_map(st->map, st->width, st->height);
    set_start(st);
    generator(st, st->width, st->height);
}
