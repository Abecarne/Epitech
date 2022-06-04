/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** zomb
*/

#include "include/defender.h"

int load_sprite_zomb(st_def *st)
{
    st->spzomb.zomb1 = sfSprite_create();
    sfSprite_setTexture(st->spzomb.zomb1, st->texg.zomb, sfFalse);
    st->spzomb.zomb2 = sfSprite_create();
    sfSprite_setTexture(st->spzomb.zomb2, st->texg.zomb, sfFalse);
    st->spzomb.zomb3 = sfSprite_create();
    sfSprite_setTexture(st->spzomb.zomb3, st->texg.zomb, sfFalse);
    st->spzomb.zomb4 = sfSprite_create();
    sfSprite_setTexture(st->spzomb.zomb4, st->texg.zomb, sfFalse);
}

void pos_zomb(st_def *st)
{
    st->spzomb.pzomb1.x = st->data.mode.width + 500;
    st->spzomb.pzomb1.y = 210;
    st->spzomb.pzomb2.x = st->data.mode.width + 800;
    st->spzomb.pzomb2.y = 350;
    st->spzomb.pzomb3.x = st->data.mode.width + 750;
    st->spzomb.pzomb3.y = 490;
    st->spzomb.pzomb4.x = st->data.mode.width + 600;
    st->spzomb.pzomb4.y = 720;
    sfSprite_setPosition(st->spzomb.zomb1, st->spzomb.pzomb1);
    sfSprite_setPosition(st->spzomb.zomb2, st->spzomb.pzomb2);
    sfSprite_setPosition(st->spzomb.zomb3, st->spzomb.pzomb3);
    sfSprite_setPosition(st->spzomb.zomb4, st->spzomb.pzomb4);
}

int disp_zomb1(sfClock *cl, sfSprite *sp, st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(cl)) > 10) {
        if (sfSprite_getPosition(sp).x < 100) {
            st->win = 3;
            return (1);
        } else {
            st->spzomb.pzomb1.x -= 0.5;
            sfSprite_setPosition(st->spzomb.zomb1, st->spzomb.pzomb1);
        }
        sfClock_restart(cl);
    }
    change_zomb1(st);
    sfRenderWindow_drawSprite(st->data.wmain, st->spzomb.zomb1, NULL);
    return (0);
}

void change_zomb1(st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(st->clzomb.zomb1)) > 500) {
        if (st->nbz.nb1 == 6) {
            st->nbz.nb1 = 0;
            st->spzomb.rzomb1.width = st->change[1][0];
            st->spzomb.rzomb1.left = st->change[0][0];
        } else {
            st->spzomb.rzomb1.width = st->change[1][st->nbz.nb1];
            st->spzomb.rzomb1.left = st->change[0][st->nbz.nb1];
            st->nbz.nb1++;
        }
        sfSprite_setTextureRect(st->spzomb.zomb1, st->spzomb.rzomb1);
        sfClock_restart(st->clzomb.zomb1);
    }
}

int zombies(st_def *st)
{
    if (disp_zomb(st->time.zomb, st->spg.zomb, st) == 1)
        return (1);
    if (disp_zomb1(st->clzomb.szomb1, st->spzomb.zomb1, st) == 1)
        return (1);
    if (disp_zomb2(st->clzomb.szomb2, st->spzomb.zomb2, st) == 1)
        return (1);
    else if (disp_zomb3(st->clzomb.szomb3, st->spzomb.zomb3, st) == 1)
        return (1);
    else
        if (disp_zomb4(st->clzomb.szomb4, st->spzomb.zomb4, st) == 1)
            return (1);
    return (0);
}