/*
** EPITECH PROJECT, 2021
** abecarne
** File description:
** turning
*/

#include "ai.h"

void move_left(sett *set, int moy)
{
    if (set->value_radar[30] < moy / 5) {
        set->wheels_dir = 0.4;
        print_dir(set->wheels_dir, set);
    } else if (set->value_radar[30] < moy / 2) {
        set->wheels_dir = 0.2;
        print_dir(set->wheels_dir, set);   
    }
}

void move_right(sett *set, int moy)
{
    if (set->value_radar[0] < moy / 5) {
        set->wheels_dir = -0.4;
        print_dir(set->wheels_dir, set);
    } else if (set->value_radar[0] < moy / 2) {
        set->wheels_dir = -0.2;
        print_dir(set->wheels_dir, set);  
    }
}

void turning_right(sett *set, int moy)
{
    if (set->value_radar[30] > 1500) {
        set->wheels_dir = -0.1;
        print_dir(set->wheels_dir, set);
    }
}

void turning_left(sett *set, int moy)
{
    if (set->value_radar[0] > 1500) {
        set->wheels_dir = 0.1;
        print_dir(set->wheels_dir, set);
    }
}