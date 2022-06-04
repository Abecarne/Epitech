/*
** EPITECH PROJECT, 2020
** draw_map.c
** File description:
** draw_map
*/

#include "my.h"
#include "framing_engine.h"

void set_map_sprite(framing *lvl)
{
    lvl->map_txt.pos.x = lvl->map_txt.x;
    lvl->map_txt.pos.y = lvl->map_txt.y;
    sfSprite_setPosition(lvl->map_txt.sprite, lvl->map_txt.pos);
}

void draw_map(framing *lvl)
{
    set_map_sprite(lvl);
    set_player_sprite(lvl);
    sfRenderWindow_drawSprite(lvl->win, lvl->map_txt.sprite, NULL);
    sfRenderWindow_drawSprite(lvl->win, lvl->player_txt.sprite, NULL);
}
