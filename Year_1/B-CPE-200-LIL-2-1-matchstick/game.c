/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** game loop
*/

#include "include/matchstick.h"

int print_end(st_match *st)
{
    if (st->win == 1) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    } else if (st->win == 2) {
        my_printf("You lost, too bad...\n");
        return (2);
    } else
        return (0);
}

int check_game(st_match *st)
{
    if (st->max_stick == 0)
        return (1);
    return (0);
}

int loop_player(st_match *st)
{
    if (turn_player(st) == 1) {
        st->win = 0;
        return (1);
    }
    return (0);
}

int gameloop(st_match *st)
{
    create_tab(st);
    while (st->max_stick != 0) {
        print_tab(st->board);
        my_putchar('\n');
        if (loop_player(st) == 1)
            break;
        if (st->max_stick == 0) {
            st->win = 2;
            break;
        }
        print_tab(st->board);
        my_putchar('\n');
        turn_ai(st);
        if (st->max_stick == 0) {
            st->win = 1;
            break;
        }
    }
    return (0);
}
