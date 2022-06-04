/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** free
*/

#include "include/defender.h"

void destroy1(st_def *st)
{
    sfRenderWindow_destroy(st->data.wmain);
    sfTexture_destroy(st->texg.heart);
    sfTexture_destroy(st->texg.zomb);
    sfTexture_destroy(st->texg.pea);
    sfTexture_destroy(st->texg.mine);
    sfTexture_destroy(st->texg.multi);
    sfTexture_destroy(st->texg.dbl);
    sfTexture_destroy(st->texg.bg);
    sfTexture_destroy(st->texg.garden);
    sfTexture_destroy(st->texg.sun);
    sfTexture_destroy(st->texm.exit);
    sfTexture_destroy(st->texm.main);
    sfTexture_destroy(st->texm.option);
    sfTexture_destroy(st->texm.play);
    sfMusic_destroy(st->music.main_menu);
    sfMusic_destroy(st->music.stage);
    sfMusic_destroy(st->music.clic);
}

void destroy2(st_def *st)
{
    sfText_destroy(st->text.menu);
    sfText_destroy(st->text.title);
    sfText_destroy(st->text.parag1);
    sfText_destroy(st->text.parag2);
    sfText_destroy(st->text.parag3);
    sfText_destroy(st->text.parag4);
    sfText_destroy(st->text.life);
    sfText_destroy(st->text.pause);
    sfText_destroy(st->text.sun);
    sfText_destroy(st->end.defeat);
    sfText_destroy(st->end.victory);
    sfSprite_destroy(st->spg.zomb);
    sfSprite_destroy(st->spg.heart);
    sfSprite_destroy(st->spg.bg);
    sfSprite_destroy(st->spg.garden);
    sfSprite_destroy(st->spg.pea);
    sfSprite_destroy(st->icon.pea);
    sfSprite_destroy(st->spg.multi);
    sfSprite_destroy(st->icon.multi);
    sfSprite_destroy(st->spg.mine);
}

void destroy3(st_def *st)
{
    sfSprite_destroy(st->icon.mine);
    sfSprite_destroy(st->spg.dbl);
    sfSprite_destroy(st->icon.dbl);
    sfSprite_destroy(st->spg.sun);
    sfSprite_destroy(st->spg.sun2);
    sfSprite_destroy(st->spm.exit);
    sfSprite_destroy(st->spm.main);
    sfSprite_destroy(st->spm.option);
    sfSprite_destroy(st->spm.play);
}

int free_all(st_def *st)
{
    destroy1(st);
    destroy2(st);
    destroy3(st);
    return (0);
}