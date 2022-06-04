/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** display_scenes
*/

#include "menu.h"

void scene_menu(st_main_menu *st)
{
    st->col->main.a = 255;
    sfSprite_setColor(st->spm->bg, st->col->main);
    sfRenderWindow_clear(st->data->wmain, sfTransparent);
    sfRenderWindow_drawSprite(st->data->wmain, st->spm->bg, NULL);
    sfRenderWindow_drawSprite(st->data->wmain, st->spm->play, NULL);
    sfRenderWindow_drawSprite(st->data->wmain, st->spm->exit, NULL);
    sfRenderWindow_drawSprite(st->data->wmain, st->spm->option, NULL);
    sfRenderWindow_display(st->data->wmain);
}

void scene_game(st_main_menu *st)
{
    sfRenderWindow_clear(st->data->wmain, sfBlue);
    sfRenderWindow_drawText(st->data->wmain, st->text.trou, NULL);
    sfRenderWindow_display(st->data->wmain);
}

void scene_pause(st_main_menu *st)
{
    st->col->pause.a = 100;
    sfSprite_setColor(st->spg->bg, st->col->pause);
    sfRenderWindow_clear(st->data->wmain, sfTransparent);
    sfRenderWindow_drawSprite(st->data->wmain, st->spg->bg, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->text.resume, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->text.inventory, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->text.option, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->text.exit, NULL);
    sfRenderWindow_display(st->data->wmain);
}

void scene_option(st_main_menu *st)
{
    st->col->main.a = 50;
    sfSprite_setColor(st->spm->bg, st->col->main);
    sfRenderWindow_clear(st->data->wmain, sfTransparent);
    sfRenderWindow_drawSprite(st->data->wmain, st->spm->bg, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->text.menu, NULL);
    sfRenderWindow_drawText(st->data->wmain, st->text.play, NULL);
    sfRenderWindow_display(st->data->wmain);
}

void scene_end(st_main_menu *st)
{
    sfRenderWindow_clear(st->data->wmain, sfWhite);
    sfRenderWindow_display(st->data->wmain);
}
