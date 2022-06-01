/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** solving
*/

#include "../include/solver.h"

void solving(st_solver *st)
{
    bool solve = false;

    solve = find_path(st, 0, 0);
    if (solve == true)
        print_solution(st);
    else
        printf("no solution found\n");
}

bool find_path(st_solver *st, int x, int y)
{
    if (x == st->column - 1 && y == st->line - 1 && st->int_map[y][x] == 0) {
        st->int_map[y][x] = 2;
        return (true);
    }
    if (valid_point(st, x, y) == true) {
        if (st->int_map[y][x] == 2)
            return (false);
        st->int_map[y][x] = 2;
        if (find_path(st, x + 1, y) == true)
            return (true);
        if (find_path(st, x, y + 1) == true)
            return (true);
        if (find_path(st, x - 1, y) == true)
            return (true);
        if (find_path(st, x, y - 1) == true)
            return (true);
        st->int_map[y][x] = 1;
        return (false);
    }
    return (false);
}