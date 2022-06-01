/*
** EPITECH PROJECT, 2021
** solver
** File description:
** main
*/

#include "../include/solver.h"

void print_solution(st_solver *st)
{
    for (int i = 0; i < st->line; i++) {
        for (int j = 0; j < st->column; j++) {
            if (st->int_map[i][j] == 0)
                printf("*");
            if (st->int_map[i][j] == 1)
                printf("X");
            if (st->int_map[i][j] == 2)
                printf("o");
        }
        if (i != st->line - 1)
            printf("\n");
    }
}

int loading_map(st_solver *st, char **av)
{
    if (recup_map(av, st) == 84)
        return (84);
    if (error_char(st) == 84)
        return (84);
    map_board(st);
    copy_map_int(st);
    return (0);
}

int main(int ac, char **av)
{
    st_solver *st = malloc(sizeof(st_solver));

    if (ac != 2)
        return (84);
    if (loading_map(st, av) == 84) {
        free_all(st);
        return (84);
    }
    solving(st);
    free_all(st);
    return (0);
}