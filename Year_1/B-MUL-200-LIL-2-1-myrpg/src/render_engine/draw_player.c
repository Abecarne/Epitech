/*
** EPITECH PROJECT, 2020
** draw_player.c
** File description:
** draw_player
*/

#include "my.h"
#include "framing_engine.h"

void set_player_sprite(framing *lvl)
{
    int status = lvl->player_txt.status;
    int anim = lvl->player_txt.animation;
    sfIntRect rect = {64 * status, 64 * anim, 64, 64};

    lvl->player_txt.pos.x = lvl->player_txt.x;
    lvl->player_txt.pos.y = lvl->player_txt.y;
    lvl->player_txt.rect = rect;
    sfSprite_setTextureRect(lvl->player_txt.sprite, lvl->player_txt.rect);
    sfSprite_setPosition(lvl->player_txt.sprite, lvl->player_txt.pos);
}

void draw_player(framing *lvl)
{
    set_player_sprite(lvl);
    sfRenderWindow_drawSprite(lvl->win, lvl->player_txt.sprite, NULL);
}
