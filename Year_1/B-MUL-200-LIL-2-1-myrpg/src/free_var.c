/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** free_var
*/

#include "menu.h"

void destroy_textures(st_main_menu *st)
{
    sfTexture_destroy(st->txm->bg);
    sfTexture_destroy(st->txg->win);
    sfTexture_destroy(st->txg->loose);
    sfTexture_destroy(st->txg->bg);
    sfTexture_destroy(st->txp->ennemi);
    sfTexture_destroy(st->txp->perso);
    sfTexture_destroy(st->txp->dos);
}

void destroy_sprites(st_main_menu *st)
{
    sfSprite_destroy(st->spm->bg);
    sfSprite_destroy(st->spm->play);
    sfSprite_destroy(st->spm->option);
    sfSprite_destroy(st->spm->exit);
    sfSprite_destroy(st->spg->loose);
    sfSprite_destroy(st->spg->win);
    sfSprite_destroy(st->spg->bg);
    sfSprite_destroy(st->spp->ennemi);
    sfSprite_destroy(st->spp->perso);
    sfSprite_destroy(st->spp->dos);
}

void destroy_text(st_main_menu *st)
{
    sfText_destroy(st->text.resume);
    sfText_destroy(st->text.inventory);
    sfText_destroy(st->text.option);
    sfText_destroy(st->text.exit);
    sfText_destroy(st->text.play);
    sfText_destroy(st->text.menu);
    sfText_destroy(st->ftxt->attack);
    sfText_destroy(st->ftxt->run);
    sfText_destroy(st->ftxt->skip);
    sfText_destroy(st->ftxt->atk1);
    sfText_destroy(st->ftxt->comp1);
    sfText_destroy(st->ftxt->comp2);
}

void destroy_musics(st_main_menu *st)
{
    sfMusic_destroy(st->music->clic);
    sfMusic_destroy(st->music->main);
    sfMusic_destroy(st->music->back);
    sfMusic_destroy(st->music->fight);
}

void free_all(st_main_menu *st)
{
    destroy_textures(st);
    destroy_sprites(st);
    destroy_musics(st);
    destroy_text(st);
    free(st->data);
    free(st->music);
    free(st);
}