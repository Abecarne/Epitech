/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** init_var2
*/

#include "menu.h"

void init_color(st_main_menu *st)
{
    st->col->main.a = 255;
    st->col->main.r = 255;
    st->col->main.g = 255;
    st->col->main.b = 255;
    sfSprite_setColor(st->spm->bg, st->col->main);
    st->col->pause.a = 255;
    st->col->pause.r = 255;
    st->col->pause.g = 255;
    st->col->pause.b = 255;
    sfSprite_setColor(st->spg->bg, st->col->pause);
}