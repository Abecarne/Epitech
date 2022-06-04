/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** sokoban
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

typedef struct sokoban
{
    char *file;
    char **map;
    int **obj;
    int nbl;
    int nbc;
    int x;
    int y;
    int input;
    int nbo;
    int end;
    int victory;
    int well_placed;
    int blocked;
}var_t;


/* ##### Fonctions ##### */
// Load
void init_struct(var_t *st);
void help(void);
void free_val(var_t *st);

// Map
void map(char **map);
void load_map(char **av, var_t *st);
void recup_map(char **av, var_t *st);
void cpt_lignmax(var_t *st);
void cpt_colmax(var_t *st);

//Game
int game_loop(var_t *st);
void init_game(var_t *st);
int check_end(var_t *st);
void movement(var_t *st);
void print_end(var_t *st);
void stuck(int i, int j, var_t *st);
void victory(var_t *st);
void defeat(var_t *st);

// Intéractions
void set_cursor(var_t *st);
void get_move(var_t *st);
void move_up(var_t *st);
void move_down(var_t *st);
void move_left(var_t *st);
void move_right(var_t *st);
void reset(var_t *st);

// Objectifs
void set_obj(var_t *st);
int over_obj(int x, int y, var_t *st);
void check_obj(var_t *st);

// Gestion erreur
int error(var_t *st);
void check_len(var_t *st);
void check_len2(void);
int check_boxes(var_t *st);
void check_map(var_t *st);
int check_player(var_t *st);
