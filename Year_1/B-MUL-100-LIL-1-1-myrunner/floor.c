/*
** EPITECH PROJECT, 2020
** projets
** File description:
** floor
*/

#include "include/struct.h"
#include "include/my.h"

void display_floor(sfRenderWindow *win, sfClock *clock)
{
    sfVector2f pos;
    for (int i = 0; i < 300; i += 48) {
        for (int j = 0; j < 1850; j += 48) {
            pos.x = 0 + j;
            pos.y = 950 - i;
            sfSprite_setPosition(var.sprite.floor, pos);
            sfRenderWindow_drawSprite(win, var.sprite.floor, NULL);
        }
    }
}