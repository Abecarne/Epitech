/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** clocks
*/

#include "include/defender.h"

void init_clocks(st_def *st)
{
    st->time.pea = sfClock_create();
    st->time.time = sfClock_create();
    st->time.zomb = sfClock_create();
    st->time.szomb = sfClock_create();
    st->time.sun = sfClock_create();
    st->time.ssun = sfClock_create();
    st->clzomb.zomb1 = sfClock_create();
    st->clzomb.szomb1 = sfClock_create();
    st->clzomb.zomb2 = sfClock_create();
    st->clzomb.szomb2 = sfClock_create();
    st->clzomb.zomb3 = sfClock_create();
    st->clzomb.szomb3 = sfClock_create();
    st->clzomb.zomb4 = sfClock_create();
    st->clzomb.szomb4 = sfClock_create();
}
