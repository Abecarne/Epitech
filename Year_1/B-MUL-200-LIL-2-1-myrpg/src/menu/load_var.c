/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** load_var
*/

#include "menu.h"

int load_textures(st_main_menu *st)
{
    st->txm->btn = sfTexture_createFromFile("res/sp/main/menu.png", sfFalse);
    if (!st->txm->btn)
        return (84);
    st->txm->bg = sfTexture_createFromFile("res/sp/main/cieux.jpg", sfFalse);
    if (!st->txm->bg)
        return (84);
    st->txg->win = sfTexture_createFromFile("res/sp/main/win.jpg", sfFalse);
    if (!st->txg->win)
        return (84);
    st->txg->loose = sfTexture_createFromFile("res/sp/main/dead.jpg", sfFalse);
    if (!st->txg->loose)
        return (84);
    st->txg->bg = sfTexture_createFromFile("res/sp/main/cieuxp.jpg", sfFalse);
    if (!st->txg->bg)
        return (84);
    return (0);
}

int load_musics(st_main_menu *st)
{
    st->music->clic = sfMusic_createFromFile("res/musics/clic.ogg");
    if (!st->music->clic)
        return (84);
    st->music->fight = sfMusic_createFromFile("res/musics/fight.ogg");
    if (!st->music->fight)
        return (84);
    st->music->back = sfMusic_createFromFile("res/musics/back_game.ogg");
    if (!st->music->back)
        return (84);
    st->music->main = sfMusic_createFromFile("res/musics/main.ogg");
    if (!st->music->main)
        return (84);
    return (0);
}

int load_sprites(st_main_menu *st)
{
    st->spm->play = sfSprite_create();
    st->spm->option = sfSprite_create();
    st->spm->exit = sfSprite_create();
    st->spm->bg = sfSprite_create();
    st->spg->loose = sfSprite_create();
    st->spg->win = sfSprite_create();
    st->spp->perso = sfSprite_create();
    st->spp->dos = sfSprite_create();
    st->spp->ennemi = sfSprite_create();
    st->spg->bg = sfSprite_create();

    return (0);
}

int load_var(st_main_menu *st)
{
    st->data->name = "Half-Way";
    if (load_textures(st) == 84)
        return (84);
    if (load_textures_perso(st) == 84)
        return (84);
    if (load_musics(st) == 84)
        return (84);
    load_sprites(st);
    return (0);
}