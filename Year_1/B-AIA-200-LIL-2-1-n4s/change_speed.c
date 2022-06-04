/*
** EPITECH PROJECT, 2021
** B-AIA-200-LIL-2-1-n4s-simon.auduberteau
** File description:
** change_speed
*/

#include "my.h"
#include "ai.h"

void change_speed(sett *set)
{
    int moy = set->value_radar[0] + set->value_radar[30];

    if (set->value_radar[15] < moy * 1.5) {
        write(1, "CAR_FORWARD:0.3\n", 15);
        get_stdin(set);
    }
    if (set->value_radar[15] < moy) {
        write(1, "CAR_FORWARD:0.2\n", 15);
        get_stdin(set);
    }
    if (set->value_radar[15] < moy * 0.75) {
        write(1, "CAR_FORWARD:0.1\n", 15);
        get_stdin(set);
    }
    get_stdin(set);
}