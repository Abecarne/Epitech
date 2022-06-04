/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** endgame
*/

#include "sokoban.h"

int check_end(var_t *st)
{
    victory(st);
    defeat(st);
    if (st->victory != 0)
        return (1);
    return (0);
}

void print_end(var_t *st)
{
    if (st->victory == 1) {
        exit (0);
    } else if (st->victory == 2) {
        exit (1);
    }
}

void victory(var_t *st)
{
    st->well_placed = 0;
    for (int i = 0; i < st->nbo; i++)
        if (st->map[st->obj[i][1]][st->obj[i][0]] == 'X')
            st->well_placed++;
    if (st->well_placed == st->nbo) {
        st->victory = 1;
    }
}

void defeat(var_t *st)
{
    st->blocked = 0;
    for (int i = 0; st->map[i] != NULL; i++) {
        for (int j = 0; st->map[i][j] != '\0'; j++) {
            if (st->map[i][j] == 'X')
                stuck(i, j, st);
            if (st->blocked == st->nbo)
                st->victory = 2;
        }
    }
}