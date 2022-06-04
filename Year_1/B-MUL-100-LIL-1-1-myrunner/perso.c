/*
** EPITECH PROJECT, 2020
** projets
** File description:
** perso
*/

#include "include/struct.h"
#include "include/my.h"

void change_perso(void)
{
    sfVector2f scale = {1.7, 1.7};
    var.img.height = 36;
    var.img.width = 31;
    var.img.left = 0 + var.change_per * 31;
    var.img.top = 0;
    sfSprite_setTexture(var.sprite.perso, var.tex.perso, sfFalse);
    sfSprite_setTextureRect(var.sprite.perso, var.img);
    sfSprite_setPosition(var.sprite.perso, var.coo.perso);
    sfSprite_setScale(var.sprite.perso, scale);
}

void update_perso(sfClock *clock, int tps)
{
    change_perso();
    if ((sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > tps)) {
        var.change_per = (var.change_per % 2) + 1;
        change_perso();
        sfClock_restart(clock);
    }
}

void display_perso(sfRenderWindow *win, sfClock *clock)
{
    update_perso(clock, 200);
    sfRenderWindow_drawSprite(win, var.sprite.perso, NULL);
}