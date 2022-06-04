/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** objectives
*/

#include "include/sokoban.h"

void set_obj(var_t *st)
{
    int nb = 0;
    int i = 0;

    st->obj = malloc(sizeof(int *) * (st->nbo + 1));
    for (int i = 0; i < st->nbo; i++)
        st->obj[i] = malloc(sizeof(int) * 2);
    for (i; st->map[i] != NULL; i++)
        for (int j = 0; st->map[i][j] != '\0'; j++)
            if (st->map[i][j] == 'O') {
                st->obj[nb][0] = j;
                st->obj[nb][1] = i;
                nb++;
            }
}

int over_obj(int x, int y, var_t *st)
{
    for (int i = 0; i < st->nbo; i++)
        if ((st->obj[i][0] == x) && (st->obj[i][1] == y)) {
            return (1);
        }
    return (0);
}

void check_obj(var_t *st)
{
    for (int i = 0; i < st->nbo; i++)
        if (st->map[st->obj[i][1]][st->obj[i][0]] == ' ')
            st->map[st->obj[i][1]][st->obj[i][0]] = 'O';
}