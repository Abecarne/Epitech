/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** buff
*/

#include "menu.h"

void get_attacked_second(st_main_menu *st, sfSprite *sp, sfVector2f origin)
{
    sfClock *mvt = sfClock_create();
    sfVector2f pos;

    while (sfTime_asMilliseconds(sfClock_getElapsedTime(mvt)) < 400) {
        if (sfSprite_getPosition(sp).x == origin.x &&
            sfTime_asMilliseconds(sfClock_getElapsedTime(mvt)) > 50) {
            pos.x = 2000;
            sfSprite_setPosition(sp, pos);
            scene_fight(st);
        } else if (sfTime_asMilliseconds(sfClock_getElapsedTime(mvt)) > 100) {
            sfSprite_setPosition(sp, origin);
            scene_fight(st);
        }
    }
    sfClock_restart(mvt);
}

void get_attacked(st_main_menu *st, sfSprite *sp)
{
    sfVector2f origin = sfSprite_getPosition(sp);

    while (1) {
        for (int i = 0; i < 5; i++) {
            get_attacked_second(st, sp, origin);
        }
        sfSprite_setPosition(sp, origin);
        break;
    }
}
