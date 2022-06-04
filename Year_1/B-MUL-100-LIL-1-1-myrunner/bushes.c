/*
** EPITECH PROJECT, 2020
** projets
** File description:
** perso
*/

#include "include/struct.h"
#include "include/my.h"

void bush1(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 5) {
        if (var.coo.bush1.x < -235 * 3.5)
            var.coo.bush1.x = 1750;
        else {
            var.coo.bush1.x -= 1;
            sfSprite_setPosition(var.sprite.bush1, var.coo.bush1);
            sfRenderWindow_drawSprite(win, var.sprite.bush1, NULL);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.bush1, NULL);
}

void bush2(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 5) {
        if (var.coo.bush2.x < -235 * 3.5)
            var.coo.bush2.x = 1750;
        else {
            var.coo.bush2.x -= 1;
            sfSprite_setPosition(var.sprite.bush2, var.coo.bush2);
            sfRenderWindow_drawSprite(win, var.sprite.bush2, NULL);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.bush2, NULL);
}

void bush3(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 5) {
        if (var.coo.bush3.x < -235 * 3.5)
            var.coo.bush3.x = 1750;
        else {
            var.coo.bush3.x -= 1;
            sfSprite_setPosition(var.sprite.bush3, var.coo.bush3);
            sfRenderWindow_drawSprite(win, var.sprite.bush3, NULL);
            sfClock_restart(clock);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.bush3, NULL);
}
