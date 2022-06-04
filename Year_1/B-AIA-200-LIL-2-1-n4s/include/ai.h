/*
** EPITECH PROJECT, 2020
** includes
** File description:
** includes
*/

#ifndef AI_H_
#define AI_H_

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <math.h>

typedef struct settings {
    float forward;
    float backward;
    float wheels_dir;
    float *value_radar;
    char *my_stdin;
} sett;

/* Initialisation */
void init_struct(sett *set);

/* IA */
void ia(void);
int check_lap(sett *s);
void get_stdin(sett *set);
void change_dir(sett *set);
void change_speed(sett *set);
float *create_lidar(sett *set);

/* Turn */
void move_left(sett *set, int moy);
void move_right(sett *set, int moy);
void print_dir(float coef, sett *set);
void turning_left(sett *set, int moy);
void turning_right(sett *set, int moy);


#endif /* !AI_H_ */
