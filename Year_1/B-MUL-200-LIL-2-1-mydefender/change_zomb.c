/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** change_zomb
*/

#include "include/defender.h"

void change_zomb2(st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(st->clzomb.zomb2)) > 500) {
        if (st->nbz.nb2 == 6) {
            st->nbz.nb2 = 0;
            st->spzomb.rzomb2.width = st->change[1][0];
            st->spzomb.rzomb2.left = st->change[0][0];
        } else {
            st->spzomb.rzomb2.width = st->change[1][st->nbz.nb2];
            st->spzomb.rzomb2.left = st->change[0][st->nbz.nb2];
            st->nbz.nb2++;
        }
        sfSprite_setTextureRect(st->spzomb.zomb2, st->spzomb.rzomb2);
        sfClock_restart(st->clzomb.zomb2);
    }
}

void change_zomb3(st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(st->clzomb.zomb3)) > 500) {
        if (st->nbz.nb3 == 6) {
            st->nbz.nb3 = 0;
            st->spzomb.rzomb3.width = st->change[1][0];
            st->spzomb.rzomb3.left = st->change[0][0];
        } else {
            st->spzomb.rzomb3.width = st->change[1][st->nbz.nb3];
            st->spzomb.rzomb3.left = st->change[0][st->nbz.nb3];
            st->nbz.nb3++;
        }
        sfSprite_setTextureRect(st->spzomb.zomb3, st->spzomb.rzomb3);
        sfClock_restart(st->clzomb.zomb3);
    }
}

void change_zomb4(st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(st->clzomb.zomb4)) > 500) {
        if (st->nbz.nb4 == 6) {
            st->nbz.nb4 = 0;
            st->spzomb.rzomb4.width = st->change[1][0];
            st->spzomb.rzomb4.left = st->change[0][0];
        } else {
            st->spzomb.rzomb4.width = st->change[1][st->nbz.nb4];
            st->spzomb.rzomb4.left = st->change[0][st->nbz.nb4];
            st->nbz.nb4++;
        }
        sfSprite_setTextureRect(st->spzomb.zomb4, st->spzomb.rzomb4);
        sfClock_restart(st->clzomb.zomb4);
    }
}