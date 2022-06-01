/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** error_map
*/
#include "../include/solver.h"

int error_char(st_solver *st)
{
    for (int y = 0; st->file[y] != '\0'; y++) {
        if (st->file[y] != '\n' && st->file[y] != '\0' && st->file[y] != '*'
        && st->file[y] != 'X')
            return (84);
    }
    return (0);
}