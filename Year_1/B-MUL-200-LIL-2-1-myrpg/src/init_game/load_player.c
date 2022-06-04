/*
** EPITECH PROJECT, 2020
** load_player.c
** File description:
** load player
*/

#include "my.h"
#include "framing_engine.h"

int load_player(framing *lvl)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {896, 512};
    sfVector2f origin = {0, 0};
    sfIntRect rect = {0, 0, 64, 64};

    lvl->player_txt.txt = sfTexture_createFromFile("assets/player.png", NULL);
    lvl->player_txt.sprite = sfSprite_create();
    lvl->player_txt.pos = pos;
    lvl->player_txt.scale = scale;
    lvl->player_txt.rect = rect;
    lvl->player_txt.x = 0;
    lvl->player_txt.y = 0;
    lvl->player_txt.status = 0;
    lvl->player_txt.animation = 0;
    lvl->player_txt.clock = sfClock_create();
    sfSprite_setTexture(lvl->player_txt.sprite, lvl->player_txt.txt, sfTrue);
    sfSprite_setTextureRect(lvl->player_txt.sprite, lvl->player_txt.rect);
    sfSprite_setScale(lvl->player_txt.sprite, lvl->player_txt.scale);
    sfSprite_setPosition(lvl->player_txt.sprite, lvl->player_txt.pos);
}
