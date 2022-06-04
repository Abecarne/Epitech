/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** zombie
*/

#include "include/defender.h"

int disp_zomb(sfClock *cl, sfSprite *sp, st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(cl)) > 10) {
        if (sfSprite_getPosition(sp).x < 100) {
            st->win = 3;
            return (1);
        } else {
            st->posg.zomb.x -= 0.5;
            sfSprite_setPosition(st->spg.zomb, st->posg.zomb);
        }
        sfClock_restart(cl);
    }
    change_zomb(st);
    sfRenderWindow_drawSprite(st->data.wmain, st->spg.zomb, NULL);
    return (0);
}

void change_zomb(st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(st->time.szomb)) > 500) {
        if (st->nb == 6) {
            st->nb = 0;
            st->rect.zomb.width = st->change[1][0];
            st->rect.zomb.left = st->change[0][0];
        } else {
            st->rect.zomb.width = st->change[1][st->nb];
            st->rect.zomb.left = st->change[0][st->nb];
            st->nb++;
        }
        sfSprite_setTextureRect(st->spg.zomb, st->rect.zomb);
        sfClock_restart(st->time.szomb);
    }
}

void init_sp_zomb(st_def *st)
{
    st->change = malloc(sizeof(int *) * 2);
    st->change[0] = malloc(sizeof(int) * 7);
    st->change[1] = malloc(sizeof(int) * 7);
    st->change[0][0] = 119;
    st->change[0][1] = 147;
    st->change[0][2] = 171;
    st->change[0][3] = 197;
    st->change[0][4] = 223;
    st->change[0][5] = 246;
    st->change[0][6] = 276;
    st->change[1][0] = 27;
    st->change[1][1] = 24;
    st->change[1][2] = 24;
    st->change[1][3] = 26;
    st->change[1][4] = 22;
    st->change[1][5] = 30;
    st->change[1][6] = 30;
}

void init_rect_zomb(st_def *st)
{
    sfVector2f scale = {2.5, 2.5};
    st->spzomb.rzomb1.height = 48;
    st->spzomb.rzomb1.width = 27;
    st->spzomb.rzomb1.left = 118;
    st->spzomb.rzomb1.top = 2;
    sfSprite_setTextureRect(st->spzomb.zomb1, st->spzomb.rzomb1);
    sfSprite_setScale(st->spzomb.zomb1, scale);
    st->spzomb.rzomb2.height = 48;
    st->spzomb.rzomb2.width = 27;
    st->spzomb.rzomb2.left = 118;
    st->spzomb.rzomb2.top = 2;
    sfSprite_setTextureRect(st->spzomb.zomb2, st->spzomb.rzomb2);
    sfSprite_setScale(st->spzomb.zomb2, scale);
    init_rect_zomb2(st, scale);
}

void init_rect_zomb2(st_def *st, sfVector2f scale)
{
    st->spzomb.rzomb3.height = 48;
    st->spzomb.rzomb3.width = 27;
    st->spzomb.rzomb3.left = 118;
    st->spzomb.rzomb3.top = 2;
    sfSprite_setTextureRect(st->spzomb.zomb3, st->spzomb.rzomb3);
    sfSprite_setScale(st->spzomb.zomb3, scale);
    st->spzomb.rzomb4.height = 48;
    st->spzomb.rzomb4.width = 27;
    st->spzomb.rzomb4.left = 118;
    st->spzomb.rzomb4.top = 2;
    sfSprite_setTextureRect(st->spzomb.zomb4, st->spzomb.rzomb4);
    sfSprite_setScale(st->spzomb.zomb4, scale);
}