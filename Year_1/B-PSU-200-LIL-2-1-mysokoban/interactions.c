/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** interactions
*/

#include "include/sokoban.h"

void get_move(var_t *st)
{
    switch (st->input) {
    case KEY_UP:
        move_up(st);
        break;
    case KEY_DOWN:
        move_down(st);
        break;
    case KEY_RIGHT:
        move_right(st);
        break;
    case KEY_LEFT:
        move_left(st);
        break;
    default:
        break;
    }
}

void move_up(var_t *st)
{
    if (st->map[st->y - 1][st->x] == 'X') {
        if (!(st->map[st->y - 2][st->x] == '#' ||
            st->map[st->y - 2][st->x] == 'X' ||
            st->y - 2 < 0)) {
            st->map[st->y - 1][st->x] = 'P';
            st->map[st->y][st->x] = ' ';
            st->map[st->y - 2][st->x] = 'X';
            st->y--;
        }
    } else if (st->map[st->y - 1][st->x] != '#' &&
            st->y - 1 > 0) {
        st->map[st->y][st->x] = ' ';
        st->map[st->y - 1][st->x] = 'P';
        st->y--;
    }
}

void move_down(var_t *st)
{
    if (st->map[st->y + 1][st->x] == 'X') {
        if (!(st->map[st->y + 2][st->x] == '#' ||
            st->map[st->y + 2][st->x] == 'X' ||
            st->y + 2 > st->nbl)) {
            st->map[st->y][st->x] = ' ';
            st->map[st->y + 1][st->x] = 'P';
            st->map[st->y + 2][st->x] = 'X';
            st->y++;
        }
    } else if (st->map[st->y + 1][st->x] != '#' &&
            st->y + 1 > 0) {
        st->map[st->y][st->x] = ' ';
        st->map[st->y + 1][st->x] = 'P';
        st->y++;
    }
}

void move_left(var_t *st)
{
    if (st->map[st->y][st->x - 1] == 'X') {
        if (!(st->map[st->y][st->x - 2] == '#' ||
            st->map[st->y][st->x - 2] == 'X' ||
            st->x - 2 < 0)) {
            st->map[st->y][st->x] = ' ';
            st->map[st->y][st->x - 1] = 'P';
            st->map[st->y][st->x - 2] = 'X';
            st->x--;
        }
    } else if (st->map[st->y][st->x - 1] != '#' &&
            st->x - 1 > 0) {
        st->map[st->y][st->x] = ' ';
        st->map[st->y][st->x - 1] = 'P';
        st->x--;
    }
}

void move_right(var_t *st)
{
    if (st->map[st->y][st->x + 1] == 'X') {
        if (!(st->map[st->y][st->x + 2] == '#' ||
            st->map[st->y][st->x + 2] == 'X' ||
            st->x + 2 > st->nbc)) {
            st->map[st->y][st->x] = ' ';
            st->map[st->y][st->x + 1] = 'P';
            st->map[st->y][st->x + 2] = 'X';
            st->x++;
        }
    } else if (st->map[st->y][st->x + 1] != '#' &&
            st->x + 1 > 0) {
        st->map[st->y][st->x] = ' ';
        st->map[st->y][st->x + 1] = 'P';
        st->x++;
    }
}
