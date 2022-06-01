/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>

/* ~~~~~~ Structures ~~~~~~ */
typedef struct solver
{
    int x;
    int y;
    char *file;
    char **map;
    int **int_map;
    int column;
    int line;
}st_solver;


/* ~~~~~~ Prototypes ~~~~~~ */
void map_board(st_solver *st);
void free_all(st_solver *st);
int error_char(st_solver *st);
int loading_map(st_solver *st, char **av);
int recup_map(char **av, st_solver *st);
void copy_map_int(st_solver *st);
void solving(st_solver *st);
void print_solution(st_solver *st);
bool valid_point(st_solver *st, int x, int y);
bool find_path(st_solver *st, int x, int y);

#endif /* !SOLVER_H_ */
