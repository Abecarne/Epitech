/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** positions2
*/

#include "include/defender.h"

void positions5(st_def *st)
{
    sfVector2f scale = {4, 4};
    sfVector2f scale2 = {3, 3};
    st->icon.ppea.x = 300;
    st->icon.ppea.y = 19;
    st->icon.pmine.x = 400;
    st->icon.pmine.y = 15;
    st->icon.pdbl.x = 500;
    st->icon.pdbl.y = 15;
    st->icon.pmulti.x = 600;
    st->icon.pmulti.y = 19;
    st->icon.psun.x = st->data.mode.width - 500;
    st->icon.psun.y = 20;
    sfSprite_setScale(st->icon.pea, scale);
    sfSprite_setScale(st->icon.mine, scale);
    sfSprite_setScale(st->icon.dbl, scale);
    sfSprite_setScale(st->icon.multi, scale);
    sfSprite_setScale(st->icon.sun, scale2);
}

void positions6(st_def *st)
{
    st->pause.resume = sfText_create();
    st->pause.main = sfText_create();
    st->pause.exit = sfText_create();
    sfText_setFont(st->pause.resume, st->text.font);
    sfText_setFont(st->pause.main, st->text.font);
    sfText_setFont(st->pause.exit, st->text.font);
    st->pause.resumepos.y = st->data.mode.height / 2;
    st->pause.mainpos.y = st->data.mode.height / 2;
    st->pause.exitpos.y = st->data.mode.height / 2;
    st->pause.resumepos.x = 0 * (st->data.mode.width / 3) + 150;
    st->pause.mainpos.x = 1 * (st->data.mode.width / 3) + 150;
    st->pause.exitpos.x = 2 * (st->data.mode.width / 3) + 150;
    sfText_setString(st->pause.resume, "RESUME");
    sfText_setString(st->pause.main, "MAIN MENU");
    sfText_setString(st->pause.exit, "EXIT");
    sfText_setPosition(st->pause.resume, st->pause.resumepos);
    sfText_setPosition(st->pause.main, st->pause.mainpos);
    sfText_setPosition(st->pause.exit, st->pause.exitpos);
}

void positions7(st_def *st)
{
    sfVector2f scale = {4, 4};
    st->rect.sun.height = 26;
    st->rect.sun.width = 26;
    st->rect.sun2.height = 26;
    st->rect.sun2.width = 26;
    st->rect.sun.left = 0;
    st->rect.sun2.left = 0;
    st->rect.sun.top = 0;
    st->rect.sun2.top = 0;
    st->posg.sun.x = 400;
    st->posg.sun2.x = 800;
    st->posg.sun.y = 500;
    st->posg.sun.y = 500;
    sfSprite_setScale(st->spg.sun, scale);
    sfSprite_setScale(st->spg.sun2, scale);
    sfSprite_setTextureRect(st->spg.sun, st->rect.sun);
    sfSprite_setTextureRect(st->spg.sun2, st->rect.sun2);
}