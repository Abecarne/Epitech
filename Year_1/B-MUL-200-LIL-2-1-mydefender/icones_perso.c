/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** icones_perso
*/

#include "include/defender.h"

void init_rect_icons(st_def *st)
{
    st->icon.rpea.height = 25;
    st->icon.rmulti.height = 25;
    st->icon.rdbl.height = 25;
    st->icon.rmine.height = 25;
    st->icon.rsun.height = 26;
    st->icon.rpea.width = 25;
    st->icon.rmine.width = 25;
    st->icon.rmulti.width = 25;
    st->icon.rdbl.width = 25;
    st->icon.rsun.width = 26;
    st->icon.rpea.left = 113;
    st->icon.rmulti.left = 265;
    st->icon.rmine.left = 209;
    st->icon.rdbl.left = 117;
    st->icon.rsun.left = 0;
    init_plus(st);
}

void init_plus(st_def *st)
{
    st->icon.rpea.top = 36;
    st->icon.rmine.top = 1;
    st->icon.rmulti.top = 0;
    st->icon.rdbl.top = 33;
    st->icon.rsun.top = 0;
    sfSprite_setTextureRect(st->icon.pea, st->icon.rpea);
    sfSprite_setTextureRect(st->icon.multi, st->icon.rmulti);
    sfSprite_setTextureRect(st->icon.mine, st->icon.rmine);
    sfSprite_setTextureRect(st->icon.dbl, st->icon.rdbl);
    sfSprite_setTextureRect(st->icon.sun, st->icon.rsun);
}

void disp_icons(st_def *st)
{
    sfSprite_setPosition(st->icon.pea, st->icon.ppea);
    sfSprite_setPosition(st->icon.dbl, st->icon.pdbl);
    sfSprite_setPosition(st->icon.mine, st->icon.pmine);
    sfSprite_setPosition(st->icon.multi, st->icon.pmulti);
    sfSprite_setPosition(st->icon.sun, st->icon.psun);
    sfRenderWindow_drawSprite(st->data.wmain, st->icon.pea, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->icon.multi, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->icon.mine, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->icon.dbl, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->icon.sun, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.sun, NULL);
}