/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-mydefender-anthony.becarne
** File description:
** display
*/

#include "include/defender.h"

void sc_menu(st_def *st)
{
    st->col.main.a = 255;
    sfSprite_setColor(st->spm.fond, st->col.main);
    sfRenderWindow_clear(st->data.wmain, sfTransparent);
    sfRenderWindow_drawSprite(st->data.wmain, st->spm.fond, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->spm.main, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->spm.play, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->spm.exit, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->spm.option, NULL);
    sfRenderWindow_display(st->data.wmain);
}

int sc_game(st_def *st)
{
    sfRenderWindow_clear(st->data.wmain, sfTransparent);
    sfRenderWindow_drawSprite(st->data.wmain, st->spg.heart, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.life, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.pause, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->spg.bg, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->spg.garden, NULL);
    if (zombies(st) == 1)
        return (1);
    disp_icons(st);
    disp_sun(st);
    sfRenderWindow_display(st->data.wmain);
    return (0);
}

void sc_pause(st_def *st)
{
    sfRenderWindow_clear(st->data.wmain, sfBlue);
    sfRenderWindow_drawText(st->data.wmain, st->pause.resume, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->pause.main, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->pause.exit, NULL);
    sfRenderWindow_display(st->data.wmain);
}

void sc_option(st_def *st)
{
    st->col.main.a = 50;
    sfRenderWindow_clear(st->data.wmain, sfBlack);
    sfSprite_setColor(st->spm.fond, st->col.main);
    sfRenderWindow_drawSprite(st->data.wmain, st->spm.fond, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.menu, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.title, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.parag1, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.parag2, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.parag3, NULL);
    sfRenderWindow_drawText(st->data.wmain, st->text.parag4, NULL);
    sfRenderWindow_display(st->data.wmain);
}

void sc_end(st_def *st)
{
    sfRenderWindow_clear(st->data.wmain, sfRed);
    sfRenderWindow_drawText(st->data.wmain, st->end.defeat, NULL);
    sfRenderWindow_drawSprite(st->data.wmain, st->spm.exit2, NULL);
    sfRenderWindow_display(st->data.wmain);
}