/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** check_input_player
*/

#include "include/matchstick.h"

bool valid_line(st_match *st)
{
    if (is_intarg(st->player->line_input) == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (false);
    }
    if (my_getnbr(st->player->line_input) <= 0 ||
        my_getnbr(st->player->line_input) > st->nbl - 2) {
        my_printf("Error: this line is out of range\n");
        return (false);
    }
    return (true);
}

bool valid_match(st_match *st)
{
    int tmp = 0;
    if (is_intarg(st->player->match_input) == 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        return (false);
    }
    tmp = my_getnbr(st->player->match_input);
    if (tmp < 1) {
        my_printf("Error: you have to remove at least one match\n");
        return (false);
    } else {
        if (tmp > st->max) {
            my_printf("Error: you cannot remove more ");
            my_printf("than %d matches per turn\n", st->max);
            return (false);
        }
        if (tmp > st->stick_per_line[st->player->line - 1][1]) {
            my_printf("Error: not enough matches on this line\n");
            return (false);
        }
    }
    return (true);
}