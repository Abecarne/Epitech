/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** loading
*/

#include "sokoban.h"

void free_val(var_t *st)
{
    free(st->file);
    for (int i = 0; st->map[i] == NULL; i++)
        free(st->map[i]);
    for (int i = 0; st->obj[i] == NULL; i++)
        free(st->obj[i]);
    curs_set(1);
    keypad(stdscr, FALSE);
}

void map(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        printw("%s", map[i]);
}

void init_struct(var_t *st)
{
    st->file = NULL;
    st->map = NULL;
    st->obj = NULL;
    st->nbc = 0;
    st->nbl = 0;
    st->x = 0;
    st->y = 0;
    st->input = 0;
    st->nbo = 0;
    st->end = 0;
    st->victory = 0;
    st->well_placed = 0;
    st->blocked = 0;
}

void check_len2(void)
{
    erase();
    move(LINES / 2 - 1, COLS / 2 - 15);
    printw("Too small to print the whole map");
    refresh();
}

void check_len(var_t *st)
{
    while ((COLS < st->nbc + 10) || (LINES < st->nbl + 5)) {
        erase();
        move(LINES / 2 - 1, COLS / 2 - 15);
        printw("Too small to print the whole map");
        refresh();
    }
}