/*
** EPITECH PROJECT, 2021
** B-AIA-200-LIL-2-1-n4s-simon.auduberteau
** File description:
** get_stdin
*/

#include "my.h"
#include "ai.h"

void get_stdin(sett *set)
{
    size_t a;

    getline(&set->my_stdin, &a, stdin);
}