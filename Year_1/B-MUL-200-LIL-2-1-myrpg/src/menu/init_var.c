/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** init_var
*/

#include "menu.h"

void init_txt(st_main_menu *st)
{
    init_text_menu(st);
    init_text_pause(st);
    init_text_fight(st);
    init_template(st);
}

void init_sprites(st_main_menu *st)
{
    sfSprite_setTexture(st->spm->play, st->txm->btn, sfFalse);
    sfSprite_setTexture(st->spm->option, st->txm->btn, sfFalse);
    sfSprite_setTexture(st->spm->exit, st->txm->btn, sfFalse);
    sfSprite_setTexture(st->spm->bg, st->txm->bg, sfFalse);
    sfSprite_setTexture(st->spg->loose, st->txg->loose, sfFalse);
    sfSprite_setTexture(st->spg->win, st->txg->win, sfFalse);
    sfSprite_setTexture(st->spg->bg, st->txg->bg, sfFalse);
    sfSprite_setTexture(st->spp->dos, st->txp->dos, sfFalse);
    sfSprite_setTexture(st->spp->ennemi, st->txp->ennemi, sfFalse);
    sfSprite_setTexture(st->spp->perso, st->txp->perso, sfFalse);

}

void init_window(st_main_menu *st)
{
    st->data->mode.width = 1600;
    st->data->mode.height = 900;
    st->data->mode.bitsPerPixel = 32;
    st->data->wmain = sfRenderWindow_create(st->data->mode, st->data->name,
                                                    sfClose, NULL);
}

void init_var(st_main_menu *st)
{
    init_window(st);
    init_positions(st);
    init_sprites(st);
    init_color(st);
    init_txt(st);
    st->sc = 0;
    st->status = 0;
}