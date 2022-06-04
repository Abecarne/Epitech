/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** gameloop
*/

#include "include/sokoban.h"

void init_game(var_t *st)
{
    keypad(stdscr, TRUE);
    curs_set(0);
    map(st->map);
    set_cursor(st);
    set_obj(st);
}

void movement(var_t *st)
{
    get_move(st);
    set_cursor(st);
    check_obj(st);
    map(st->map);
}

void reset(var_t *st)
{
    st->map = str_to_array(st->file);
}
