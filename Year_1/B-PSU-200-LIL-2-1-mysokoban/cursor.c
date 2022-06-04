/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** cursor
*/

#include "sokoban.h"

void set_cursor(var_t *st)
{
    for (int i = 0; st->map[i] != NULL; i++)
        for (int j = 0; st->map[i][j] != '\0'; j++)
            if (st->map[i][j] == 'P') {
                st->y = i;
                st->x = j;
                break;
            }
}
