/*
** EPITECH PROJECT, 2021
** sem2 [WSL: Ubuntu-20.04]
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include "my.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

/* ~~~~~~ Structures ~~~~~~ */
typedef struct generator
{
    int x;
    int y;
    int x1;
    int y1;
    int x2;
    int y2;
    int dx;
    int dy;
    int width;
    int height;
    int **map;
}st_generator;

/* ~~~~~~ Prototypes ~~~~~~ */
void print_map(st_generator *st);
int check_movement(st_generator *st);
void move_to_next(st_generator *st);
void maze(st_generator *st);
void set_start(st_generator *st);
int **malloc_map(int **map, int width, int height);

#endif /* !GENERATOR_H_ */
