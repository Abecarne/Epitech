/*
** EPITECH PROJECT, 2020
** projets
** File description:
** help
*/

#include "include/struct.h"

void random_wall(int i)
{
    srand(time(NULL));
    int min = 1750;
    int max = 1750 * 2 - 100;

    if (i == 0)
        var.coo.wall.x = (rand() %  (max - min) + 1) + min;
    else if (i == 1)
        var.coo.wall2.x = (rand() % (max - min) + 1) + min;
    sfSprite_setPosition(var.sprite.wall, var.coo.wall);
    sfSprite_setPosition(var.sprite.wall2, var.coo.wall2);
}

void move_wall(void)
{
    int xfire = sfSprite_getPosition(var.sprite.ball).x;
    int yfire = sfSprite_getPosition(var.sprite.ball).y;

    if (sfTime_asMilliseconds(sfClock_getElapsedTime(var.clock.mv_mob)) > 5) {
        var.coo.wall.x -= 2;
        sfSprite_setPosition(var.sprite.wall, var.coo.wall);
        var.coo.wall2.x -= 2;
        sfSprite_setPosition(var.sprite.wall2, var.coo.wall2);
    }
    if (var.coo.wall.x < -100) {
        random_wall(0);
        var.text.change++;
    }
    if (var.coo.wall2.x < -100) {
        random_wall(1);
        var.text.change++;
    }
}

void change_wall(void)
{
    sfSprite_setTexture(var.sprite.wall, var.tex.floor, sfFalse);
    sfSprite_setPosition(var.sprite.wall, var.coo.wall);
    sfSprite_setTexture(var.sprite.wall2, var.tex.floor, sfFalse);
    sfSprite_setPosition(var.sprite.wall2, var.coo.wall2);
}

void update_wall(void)
{
    change_wall();
    move_wall();
}

void display_wall(void)
{
    update_wall();
    sfRenderWindow_drawSprite(var.data.window, var.sprite.wall, NULL);
    sfRenderWindow_drawSprite(var.data.window, var.sprite.wall2, NULL);
}