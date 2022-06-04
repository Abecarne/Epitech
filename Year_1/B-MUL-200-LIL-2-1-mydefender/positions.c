/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** positions
*/

#include "include/defender.h"

void positions1(st_def *st)
{
    st->posm.logo.x = st->data.mode.width / 4;
    st->posm.logo.y = 100;
    sfSprite_setPosition(st->spm.main, st->posm.logo);
    st->rect.play.height = 186;
    st->rect.play.width = 286;
    st->rect.play.top = 0;
    st->rect.play.left = 0;
    sfSprite_setTextureRect(st->spm.play, st->rect.play);
    st->posm.play.x = 150;
    st->posm.play.y = st->data.mode.height / 1.35;
    sfSprite_setPosition(st->spm.play, st->posm.play);
    st->rect.option.height = 186;
    st->rect.option.width = 286;
    st->rect.option.top = 186;
    st->rect.option.left = 0;
    sfSprite_setTextureRect(st->spm.option, st->rect.option);
    st->posm.option.x = st->data.mode.width / 3 + 150;
    st->posm.option.y = st->data.mode.height / 1.35;
    sfSprite_setPosition(st->spm.option, st->posm.option);
}

void positions2(st_def *st)
{
    st->rect.exit.height = 186;
    st->rect.exit.width = 286;
    st->rect.exit.top = 186 * 2;
    st->rect.exit.left = 0;
    sfSprite_setTextureRect(st->spm.exit, st->rect.exit);
    st->posm.exit.x = 2 * (st->data.mode.width / 3) + 150;
    st->posm.exit.y = st->data.mode.height / 1.35;
    sfSprite_setPosition(st->spm.exit, st->posm.exit);
    st->rect.exit2.height = 186;
    st->rect.exit2.width = 286;
    st->rect.exit2.top = 186 * 2;
    st->rect.exit2.left = 0;
    sfSprite_setTextureRect(st->spm.exit2, st->rect.exit2);
    st->posm.exit2.x = st->data.mode.width / 2 - 150;
    st->posm.exit2.y = st->data.mode.height / 1.35;
    sfSprite_setPosition(st->spm.exit2, st->posm.exit2);
    sfVector2f scale = {1.3, 1.3};
    sfSprite_setScale(st->spm.fond, scale);
}

void positions3(st_def *st)
{
    sfVector2f scale = {4.3, 4.3};
    st->rect.bg.height = 207;
    st->rect.bg.width = 415;
    st->rect.bg.top = 5;
    st->rect.bg.left = 5;
    sfSprite_setTextureRect(st->spg.bg, st->rect.bg);
    st->posg.bg.x = 0;
    st->posg.bg.y = st->data.mode.height - 3.65 * st->rect.bg.height;
    sfSprite_setPosition(st->spg.bg, st->posg.bg);
    sfSprite_setScale(st->spg.bg, scale);
    st->rect.garden.height = 175;
    st->rect.garden.width = 230;
    st->rect.garden.top = 228;
    st->rect.garden.left = 234;
    sfSprite_setTextureRect(st->spg.garden, st->rect.garden);
    st->posg.garden.x = 292;
    st->posg.garden.y = st->data.mode.height - 3.65 *
                        st->rect.garden.height - 57;
    sfSprite_setPosition(st->spg.garden, st->posg.garden);
    sfSprite_setScale(st->spg.garden, scale);
}

void positions4(st_def *st)
{
    sfVector2f scale = {2.5, 2.5};
    st->rect.zomb.height = 48;
    st->rect.zomb.width = 27;
    st->rect.zomb.left = 118;
    st->rect.zomb.top = 2;
    sfSprite_setTextureRect(st->spg.zomb, st->rect.zomb);
    sfSprite_setScale(st->spg.zomb, scale);
    st->posg.zomb.x = 2000;
    st->posg.zomb.y = 600;
    sfSprite_setPosition(st->spg.zomb, st->posg.zomb);
    sfVector2f size = {4, 4};
    st->posg.heart.x = st->data.mode.width - 170;
    st->posg.heart.y = 20;
    sfSprite_setPosition(st->spg.heart, st->posg.heart);
    sfSprite_setScale(st->spg.heart, size);
}

void init_positions(st_def *st)
{
    positions1(st);
    positions2(st);
    positions3(st);
    positions4(st);
    positions5(st);
    positions6(st);
    positions7(st);
    init_sp_zomb(st);
    pos_zomb(st);
}
