/*
** EPITECH PROJECT, 2021
** solver
** File description:
** main
*/

#include "../include/solver.h"

void free_all(st_solver *st)
{
    for (int i = 0; i < st->line; i++) {
        free(st->map[i]);
        free(st->int_map[i]);
    }
    free(st->int_map);
    free(st->map);
    free(st->file);
    free(st);
}