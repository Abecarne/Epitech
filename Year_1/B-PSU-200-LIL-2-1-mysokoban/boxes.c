/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** boxes
*/

#include "sokoban.h"

void stuck(int i, int j, var_t *st)
{
    if (over_obj(i, j, st) != 1) {
        if ((st->map[i - 1][j] == '#' || st->map[i - 1][j] == 'X') &&
            (st->map[i][j + 1] == '#' || st->map[i][j + 1] == 'X'))
            st->blocked++;
        if ((st->map[i][j + 1] == '#' || st->map[i][j + 1] == 'X') &&
            (st->map[i + 1][j] == '#' || st->map[i + 1][j] == 'X'))
            st->blocked++;
        if ((st->map[i + 1][j] == '#' || st->map[i + 1][j] == 'X') &&
            (st->map[i][j - 1] == '#' || st->map[i][j - 1] == 'X'))
            st->blocked++;
        else if ((st->map[i][j - 1] == '#' || st->map[i][j - 1] == 'X') &&
                (st->map[i - 1][j] == '#' || st->map[i - 1][j] == 'X'))
            st->blocked++;
    }
}
