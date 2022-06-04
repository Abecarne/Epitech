/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** positions
*/

#include "menu.h"

void positions1(st_main_menu *st)
{
    st->rect->play.height = 186;
    st->rect->play.width = 286;
    st->rect->play.top = 0;
    st->rect->play.left = 0;
    sfSprite_setTextureRect(st->spm->play, st->rect->play);
    st->posm->play.x = 150;
    st->posm->play.y = st->data->mode.height / 1.35;
    sfSprite_setPosition(st->spm->play, st->posm->play);
    st->rect->option.height = 186;
    st->rect->option.width = 286;
    st->rect->option.top = 186;
    st->rect->option.left = 0;
    sfSprite_setTextureRect(st->spm->option, st->rect->option);
    st->posm->option.x = st->data->mode.width / 3 + 150;
    st->posm->option.y = st->data->mode.height / 1.35;
    sfSprite_setPosition(st->spm->option, st->posm->option);
}

void positions2(st_main_menu *st)
{
    st->rect->exit.height = 186;
    st->rect->exit.width = 286;
    st->rect->exit.top = 186 * 2;
    st->rect->exit.left = 0;
    sfSprite_setTextureRect(st->spm->exit, st->rect->exit);
    st->posm->exit.x = 2 * (st->data->mode.width / 3) + 150;
    st->posm->exit.y = st->data->mode.height / 1.35;
    sfSprite_setPosition(st->spm->exit, st->posm->exit);
}

void init_positions(st_main_menu *st)
{
    positions1(st);
    positions2(st);
}
