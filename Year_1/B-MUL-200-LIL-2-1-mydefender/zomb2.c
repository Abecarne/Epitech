/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** zomb2
*/

#include "include/defender.h"

int disp_zomb2(sfClock *cl, sfSprite *sp, st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(cl)) > 10) {
        if (sfSprite_getPosition(sp).x < 100) {
            st->win = 3;
            return (1);
        } else {
            st->spzomb.pzomb2.x -= 0.5;
            sfSprite_setPosition(st->spzomb.zomb2, st->spzomb.pzomb2);
        }
        sfClock_restart(cl);
    }
    change_zomb2(st);
    sfRenderWindow_drawSprite(st->data.wmain, st->spzomb.zomb2, NULL);
    return (0);
}

int disp_zomb3(sfClock *cl, sfSprite *sp, st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(cl)) > 10) {
        if (sfSprite_getPosition(sp).x < 100) {
            st->win = 3;
            return (1);
        } else {
            st->spzomb.pzomb3.x -= 0.5;
            sfSprite_setPosition(st->spzomb.zomb3, st->spzomb.pzomb3);
        }
        sfClock_restart(cl);
    }
    change_zomb3(st);
    sfRenderWindow_drawSprite(st->data.wmain, st->spzomb.zomb3, NULL);
    return (0);
}

int disp_zomb4(sfClock *cl, sfSprite *sp, st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(cl)) > 10) {
        if (sfSprite_getPosition(sp).x < 100) {
            st->win = 3;
            return (1);
        } else {
            st->spzomb.pzomb4.x -= 0.5;
            sfSprite_setPosition(st->spzomb.zomb4, st->spzomb.pzomb4);
        }
        sfClock_restart(cl);
    }
    change_zomb4(st);
    sfRenderWindow_drawSprite(st->data.wmain, st->spzomb.zomb4, NULL);
    return (0);
}
