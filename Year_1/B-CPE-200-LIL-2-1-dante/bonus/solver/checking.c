/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** checking
*/

#include "../include/solver.h"

bool valid_point(st_solver *st, int x, int y)
{
    if (x < 0 || x >= st->column || y < 0 || y >= st->line ||
        st->int_map[y][x] != 0)
        return (false);
    else
        return (true);
}
