/*
** EPITECH PROJECT, 2020
** projets
** File description:
** window
*/

#include "include/struct.h"
#include "include/my.h"

void destroy1(void)
{
    sfTexture_destroy(var.tex.floor);
    sfTexture_destroy(var.tex.perso);
    sfTexture_destroy(var.tex.bush);
    sfTexture_destroy(var.tex.mountain);
    sfTexture_destroy(var.tex.cloud);
    sfTexture_destroy(var.tex.mob);
    sfSprite_destroy(var.sprite.floor);
    sfSprite_destroy(var.sprite.perso);
    sfSprite_destroy(var.sprite.bush1);
    sfSprite_destroy(var.sprite.bush2);
    sfSprite_destroy(var.sprite.bush2);
    sfSprite_destroy(var.sprite.mountain1);
    sfSprite_destroy(var.sprite.mountain2);
    sfSprite_destroy(var.sprite.mountain3);
    sfSprite_destroy(var.sprite.cloud1);
    sfSprite_destroy(var.sprite.cloud2);
    sfSprite_destroy(var.sprite.cloud3);
    sfSprite_destroy(var.sprite.mob);
    sfSprite_destroy(var.sprite.mb2);
}

void destroy2(void)
{
    sfMusic_destroy(var.music.back);
    sfMusic_destroy(var.music.jump);
    sfMusic_destroy(var.music.fire);
    sfMusic_destroy(var.music.death);
    sfMusic_destroy(var.music.win);
    sfClock_destroy(var.clock.perso);
    sfClock_destroy(var.clock.mountain);
    sfClock_destroy(var.clock.cloud);
    sfClock_destroy(var.clock.floor);
    sfClock_destroy(var.clock.bush);
    sfClock_destroy(var.clock.time);
    sfClock_destroy(var.clock.total);
    sfFont_destroy(var.text.font);
    sfText_destroy(var.text.lose);
    sfText_destroy(var.text.score);
    sfText_destroy(var.text.value);
    sfText_destroy(var.text.win);
}

