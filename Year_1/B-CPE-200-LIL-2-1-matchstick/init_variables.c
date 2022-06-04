/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** init_variables
*/

#include "include/matchstick.h"

void init_values(char **av, st_match *st)
{
    st->nbl = my_getnbr(av[1]) + 2;
    st->max = my_getnbr(av[2]);
    st->nbc = my_getnbr((av[1])) * 2 + 1;
    st->max_stick = my_getnbr(av[1]) * my_getnbr(av[1]);
}

void init_struct(char **av, st_match *st)
{
    st->max = 0;
    st->nbc = 0;
    st->nbl = 0;
    st->win = 0;
    st->status = 0;
    st->player->line = 0;
    st->player->match = 0;
    st->bot->line = 0;
    st->bot->match = 1;
    st->max_stick = 0;
    st->player->line_input = NULL;
    st->player->match_input = NULL;
    init_values(av, st);
}

void free_all(st_match *st)
{
    for (int i = 0; st->board[i] != NULL; i++)
        free(st->board[i]);
    free(st->player->line_input);
    free(st->player->match_input);
    for (int i = 0; st->stick_per_line[i] != NULL; i++)
        free(st->stick_per_line[i]);
}