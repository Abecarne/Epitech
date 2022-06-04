/*
** EPITECH PROJECT, 2020
** projets
** File description:
** perso
*/

#include "include/struct.h"
#include "include/my.h"

void mountain1(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 15) {
        if (var.coo.mountain1.x < -235 * 3.5)
            var.coo.mountain1.x = 1750;
        else {
            var.coo.mountain1.x -= 1;
            sfSprite_setPosition(var.sprite.mountain1, var.coo.mountain1);
            sfRenderWindow_drawSprite(win, var.sprite.mountain1, NULL);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.mountain1, NULL);
}

void mountain2(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 15) {
        if (var.coo.mountain2.x < -235 * 3.5)
            var.coo.mountain2.x = 1750;
        else {
            var.coo.mountain2.x -= 1;
            sfSprite_setPosition(var.sprite.mountain2, var.coo.mountain2);
            sfRenderWindow_drawSprite(win, var.sprite.mountain2, NULL);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.mountain2, NULL);
}

void mountain3(sfRenderWindow *win, sfClock *clock)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(clock)) > 15) {
        if (var.coo.mountain3.x < -235 * 3.5)
            var.coo.mountain3.x = 1750;
        else {
            var.coo.mountain3.x -= 1;
            sfSprite_setPosition(var.sprite.mountain3, var.coo.mountain3);
            sfRenderWindow_drawSprite(win, var.sprite.mountain3, NULL);
            sfClock_restart(clock);
        }
    } else
        sfRenderWindow_drawSprite(win, var.sprite.mountain3, NULL);
}
