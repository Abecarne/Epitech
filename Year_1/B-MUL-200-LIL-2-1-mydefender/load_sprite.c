/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** load_sprite
*/

#include "include/defender.h"

void load_sprites1(st_def *st)
{
    st->spm.fond = sfSprite_create();
    sfSprite_setTexture(st->spm.fond, st->texm.fond, sfFalse);
    st->spm.main = sfSprite_create();
    sfSprite_setTexture(st->spm.main, st->texm.main, sfFalse);
    st->spm.play = sfSprite_create();
    sfSprite_setTexture(st->spm.play, st->texm.play, sfFalse);
    st->spm.exit = sfSprite_create();
    sfSprite_setTexture(st->spm.exit, st->texm.exit, sfFalse);
    st->spm.exit2 = sfSprite_create();
    sfSprite_setTexture(st->spm.exit2, st->texm.exit, sfFalse);
    st->spm.option = sfSprite_create();
    sfSprite_setTexture(st->spm.option, st->texm.option, sfFalse);
}

void load_sprites2(st_def *st)
{
    st->spg.bg = sfSprite_create();
    sfSprite_setTexture(st->spg.bg, st->texg.bg, sfFalse);
    st->spg.garden = sfSprite_create();
    sfSprite_setTexture(st->spg.garden, st->texg.bg, sfFalse);
    st->spg.pea = sfSprite_create();
    sfSprite_setTexture(st->spg.pea, st->texg.pea, sfFalse);
    st->spg.sun = sfSprite_create();
    sfSprite_setTexture(st->spg.sun, st->texg.sun, sfFalse);
    st->spg.mine = sfSprite_create();
    sfSprite_setTexture(st->spg.mine, st->texg.mine, sfFalse);
    st->spg.zomb = sfSprite_create();
    sfSprite_setTexture(st->spg.zomb, st->texg.zomb, sfFalse);
    st->spg.heart = sfSprite_create();
    sfSprite_setTexture(st->spg.heart, st->texg.heart, sfFalse);
}

void load_sprites3(st_def *st)
{
    st->spg.dbl = sfSprite_create();
    sfSprite_setTexture(st->spg.dbl, st->texg.dbl, sfFalse);
    st->spg.multi = sfSprite_create();
    sfSprite_setTexture(st->spg.multi, st->texg.multi, sfFalse);
    st->icon.pea = sfSprite_create();
    sfSprite_setTexture(st->icon.pea, st->texg.pea, sfFalse);
    st->icon.mine = sfSprite_create();
    sfSprite_setTexture(st->icon.mine, st->texg.mine, sfFalse);
    st->icon.multi = sfSprite_create();
    sfSprite_setTexture(st->icon.multi, st->texg.multi, sfFalse);
    st->icon.dbl = sfSprite_create();
    sfSprite_setTexture(st->icon.dbl, st->texg.dbl, sfFalse);
    st->icon.sun = sfSprite_create();
    sfSprite_setTexture(st->icon.sun, st->texg.sun, sfFalse);
    st->spg.sun2 = sfSprite_create();
    sfSprite_setTexture(st->spg.sun2, st->texg.sun, sfFalse);
}

void load_sprites(st_def *st)
{
    load_sprites1(st);
    load_sprites2(st);
    load_sprites3(st);
    load_sprite_zomb(st);
}