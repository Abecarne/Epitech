/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** print + calcul map
*/

#include "include/matchstick.h"

void print_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_printf("%s\n", tab[i]);
    }
}

void fill_map(st_match *st)
{
    int stick = st->nbc - 2;
    int space = 1;

    for (int i = st->nbl - 2; i > 0; i--, stick -= 2) {
        for (int j = space; j < stick + space; j++)
            st->board[i][j] = '|';
        space++;
    }
}

void create_tab(st_match *st)
{
    int i = 0;
    int j = 0;

    st->board = malloc(sizeof(char *) * (st->nbl + 1));
    for (i = 0; i != st->nbl; i++) {
        st->board[i] = malloc(sizeof(char) * st->nbc + 1);
        for (j = 0; j != st->nbc; j++)
            if (i == 0 || i == st->nbl - 1 || j == 0 || j == st->nbc - 1)
                st->board[i][j] = '*';
            else
                st->board[i][j] = ' ';
        st->board[i][j] = '\0';
    }
    st->board[i] = NULL;
    fill_map(st);
}

void array_stick(st_match *st)
{
    int i = 0;

    st->stick_per_line = malloc(sizeof(int *) * st->nbl - 1);
    for (i = 0; i < st->nbl - 2; i++) {
        st->stick_per_line[i] = malloc(sizeof(int) * 2);
        st->stick_per_line[i][0] = i + 1;
        st->stick_per_line[i][1] = i * 2 + 1;
    }
    st->stick_per_line[i] = NULL;
}