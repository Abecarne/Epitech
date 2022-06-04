/*
** EPITECH PROJECT, 2021
** B-AIA-200-LIL-2-1-n4s-simon.auduberteau
** File description:
** init_struct
*/

#include "ai.h"

void init_struct(sett *set)
{
    set->forward = 1.0;
    set->backward = 0;
    set->wheels_dir = 0;
    set->value_radar = malloc(sizeof(float) * 64);
    set->my_stdin = malloc(sizeof(char) * 512);
}