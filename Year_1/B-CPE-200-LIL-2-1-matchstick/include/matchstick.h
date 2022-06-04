/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/* ~~~~~~ Structures ~~~~~~ */
typedef struct player
{
    int line;
    int match;
    char *line_input;
    char *match_input;
}st_player;

typedef struct ai
{
    int line;
    int match;
}st_ai;

typedef struct matchstick
{
    int a;
    int nbl;
    int win;
    int nbc;
    int max;
    int status;
    int max_stick;
    int **stick_per_line;
    char **board;
    st_player *player;
    st_ai *bot;
}st_match;


/* ~~~~~~ Prototypes ~~~~~~ */
void turn_ai(st_match *st);
void print_tab(char **tab);
void free_all(st_match *st);
void create_tab(st_match *st);
void array_stick(st_match *st);
void init_values(char **av, st_match *st);
void init_struct(char **av, st_match *st);
int is_intarg(char *str);
int gameloop(st_match *st);
int print_end(st_match *st);
int error(int ac, char **av);
int turn_player(st_match *st);
bool valid_line(st_match *st);
bool valid_match(st_match *st);

#endif /* !MATCHSTICK_H_ */
