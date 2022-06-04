/*
** EPITECH PROJECT, 2020
** projets
** File description:
** main
*/

#include "include/struct.h"
#include "include/my.h"

void textures(void)
{
    var.tex.floor = sfTexture_createFromFile("pictures/floor.png", NULL);
    var.tex.perso = sfTexture_createFromFile("pictures/running.png", NULL);
    var.tex.ball = sfTexture_createFromFile("pictures/ball.png", NULL);
    var.tex.bush = sfTexture_createFromFile("pictures/bushes.png", NULL);
    var.tex.mountain = sfTexture_createFromFile("pictures/mountains.png", NULL);
    var.tex.cloud = sfTexture_createFromFile("pictures/clouds.png", NULL);
    var.tex.mob = sfTexture_createFromFile("pictures/gomba.png", NULL);
}

void sprites(void)
{
    sfVector2f size = {3, 3};
    var.sprite.mob = sfSprite_create();
    sfSprite_setTexture(var.sprite.mob, var.tex.mob, sfFalse);
    var.sprite.mb2 = sfSprite_create();
    sfSprite_setTexture(var.sprite.mb2, var.tex.mob, sfFalse);
    var.sprite.floor = sfSprite_create();
    sfSprite_setTexture(var.sprite.floor, var.tex.floor, sfFalse);
    var.sprite.perso = sfSprite_create();
    sfSprite_setTexture(var.sprite.perso, var.tex.perso, sfFalse);
    var.sprite.ball = sfSprite_create();
    sfSprite_setTexture(var.sprite.ball, var.tex.ball, sfFalse);
    var.sprite.cloud1 = sfSprite_create();
    sfSprite_setTexture(var.sprite.cloud1, var.tex.cloud, sfFalse);
    sfSprite_setScale(var.sprite.cloud1, size);
    var.sprite.cloud2 = sfSprite_create();
    sfSprite_setTexture(var.sprite.cloud2, var.tex.cloud, sfFalse);
    sfSprite_setScale(var.sprite.cloud2, size);
    var.sprite.cloud3 = sfSprite_create();
    sfSprite_setTexture(var.sprite.cloud3, var.tex.cloud, sfFalse);
    sfSprite_setScale(var.sprite.cloud3, size);
}

void sprites2(void)
{
    sfVector2f size = {3.5, 3.5};
    sfVector2f size2 = {2.5, 2.5};
    var.sprite.bush1 = sfSprite_create();
    sfSprite_setTexture(var.sprite.bush1, var.tex.bush, sfFalse);
    sfSprite_setScale(var.sprite.bush1, size2);
    var.sprite.bush2 = sfSprite_create();
    sfSprite_setTexture(var.sprite.bush2, var.tex.bush, sfFalse);
    sfSprite_setScale(var.sprite.bush2, size2);
    var.sprite.bush3 = sfSprite_create();
    sfSprite_setTexture(var.sprite.bush3, var.tex.bush, sfFalse);
    sfSprite_setScale(var.sprite.bush3, size2);
    var.sprite.mountain1 = sfSprite_create();
    sfSprite_setTexture(var.sprite.mountain1, var.tex.mountain, sfFalse);
    sfSprite_setScale(var.sprite.mountain1, size);
    var.sprite.mountain2 = sfSprite_create();
    sfSprite_setTexture(var.sprite.mountain2, var.tex.mountain, sfFalse);
    sfSprite_setScale(var.sprite.mountain2, size);
    var.sprite.mountain3 = sfSprite_create();
    sfSprite_setTexture(var.sprite.mountain3, var.tex.mountain, sfFalse);
    sfSprite_setScale(var.sprite.mountain3, size);
}

void sprites3(void)
{
    var.sprite.wall = sfSprite_create();
    sfSprite_setTexture(var.sprite.wall, var.tex.floor, sfFalse);
    var.sprite.wall2 = sfSprite_create();
    sfSprite_setTexture(var.sprite.wall2, var.tex.floor, sfFalse);
}

int music(void)
{
    var.music.jump = sfMusic_createFromFile("music/jump.ogg");
    if (!var.music.jump)
        return (84);
    var.music.back = sfMusic_createFromFile("music/background.ogg");
    if (!var.music.back)
        return (84);
    var.music.fire = sfMusic_createFromFile("music/fireball.ogg");
    if (!var.music.fire)
        return (84);
    var.music.death = sfMusic_createFromFile("music/lose.ogg");
    if (!var.music.death)
        return (84);
    var.music.win = sfMusic_createFromFile("music/win.ogg");
    if (!var.music.win)
        return (84);
    return (0);
}