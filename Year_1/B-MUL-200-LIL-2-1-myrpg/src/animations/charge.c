/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** buff
*/

#include "menu.h"

void charge_anim(st_main_menu *st, sfSprite *att, sfSprite *def)
{
    sfClock *mvt = sfClock_create();

    st->spp->dospos.x = 150;
    while (st->spp->dospos.x < 500) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(mvt)) > 5) {
            st->spp->dospos.x += 7;
            sfSprite_setPosition(att, st->spp->dospos);
            scene_fight(st);
            sfClock_restart(mvt);
        }
    }
    get_attacked(st, def);
    while (st->spp->dospos.x > 150) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(mvt)) > 5) {
            st->spp->dospos.x -= 7;
            sfSprite_setPosition(att, st->spp->dospos);
            scene_fight(st);
            sfClock_restart(mvt);
        }
    }
}