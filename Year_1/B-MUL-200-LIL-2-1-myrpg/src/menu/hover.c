/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** hover
*/

#include "menu.h"

int hover_menu(st_main_menu *st)
{
    if (hover_play(st, st->spm->play) == 1)
        return (1);
    if (hover_opt(st, st->spm->option) == 1)
        return (1);
    if (hover_exit(st, st->spm->exit) == 1)
        return (1);
    return (0);
}

int hover_pause(st_main_menu *st)
{
    if (hover_presume(st, st->text.resume) == 1)
        return (1);
    if (hover_pinventory(st, st->text.inventory) == 1)
        return (1);
    if (hover_popt(st, st->text.option) == 1)
        return (1);
    if (hover_pexit(st, st->text.exit) == 1)
        return (1);
    return (0);
}

int hover_option(st_main_menu *st)
{
    if (hover_oopt(st, st->text.menu) == 1)
        return (1);
    if (hover_oplay(st, st->text.play) == 1)
        return (1);
    return (0);
}