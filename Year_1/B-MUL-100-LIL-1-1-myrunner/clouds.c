/*
** EPITECH PROJECT, 2020
** projets
** File description:
** perso
*/

#include "include/struct.h"
#include "include/my.h"

void cloud1(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 10) {
        if (var.coo.cloud1.x < -235 * 3.5)
            var.coo.cloud1.x = 1750;
        else {
            var.coo.cloud1.x -= 1;
            sfSprite_setPosition(var.sprite.cloud1, var.coo.cloud1);
            sfRenderWindow_drawSprite(win, var.sprite.cloud1, NULL);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.cloud1, NULL);
}

void cloud2(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 10) {
        if (var.coo.cloud2.x < -235 * 3.5)
            var.coo.cloud2.x = 1750;
        else {
            var.coo.cloud2.x -= 1;
            sfSprite_setPosition(var.sprite.cloud2, var.coo.cloud2);
            sfRenderWindow_drawSprite(win, var.sprite.cloud2, NULL);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.cloud2, NULL);
}

void cloud3(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 10) {
        if (var.coo.cloud3.x < -235 * 3.5)
            var.coo.cloud3.x = 1750;
        else {
            var.coo.cloud3.x -= 1;
            sfSprite_setPosition(var.sprite.cloud3, var.coo.cloud3);
            sfRenderWindow_drawSprite(win, var.sprite.cloud3, NULL);
            sfClock_restart(clock);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.cloud3, NULL);
}
