/*
** EPITECH PROJECT, 2021
** B-AIA-200-LIL-2-1-n4s-simon.auduberteau
** File description:
** wheels_dir
*/

#include "my.h"
#include "ai.h"

void print_dir(float coef, sett *set)
{
    char ans[100];
    sprintf(ans, "%.1f", coef);
        write(1, "WHEELS_DIR:", 11);
    write(1, ans, my_strlen(ans));
    write(1, "\n", 1);
    get_stdin(set);
}

void change_dir(sett *set)
{
    int moy = set->value_radar[0] + set->value_radar[30];

    move_left(set, moy);
    move_right(set, moy);
    turning_left(set, moy);
    turning_right(set, moy);
    if (set->value_radar[0] < (moy / 2) - (moy / 5) &&
        set->value_radar[30] < (moy / 2) - (moy / 5)) {
        set->wheels_dir = 0.0;
        print_dir(set->wheels_dir, set);
    }
    check_lap(set);
}