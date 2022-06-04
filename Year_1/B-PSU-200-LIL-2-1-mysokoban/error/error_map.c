/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** error_map
*/

#include "../include/sokoban.h"

void check_map(var_t *st)
{
    for (int i = 0; st->file[i] != 0; i++)
        if (st->file[i] != '#' && st->file[i] != 'P' && st->file[i] != 'O'
            && st->file[i] != 'X' && st->file[i] != '\n' && st->file[i] != '\0'
            && st->file[i] != ' ') {
                exit(84);
            }
}

int check_boxes(var_t *st)
{
    int box = 0;

    for (int i = 0; st->file[i] != '\0'; i++) {
        if (st->file[i] == 'X')
            box++;
        if (st->file[i] == 'O')
            st->nbo++;
    }
    if (st->nbo != box || box == 0) {
        exit(84);
    }
    return (0);
}

int check_player(var_t *st)
{
    int cpt_player = 0;

    for (int i = 0; st->file[i] != '\0'; i++)
        if (st->file[i] == 'P')
            cpt_player++;
    if (cpt_player != 1) {
        exit(84);
    }
    return (0);
}