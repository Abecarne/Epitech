/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fight_var
*/

#include "menu.h"

void init_heart(void)
{
    st_entity *heart = malloc(sizeof(st_entity));
    heart->texture = sfTexture_createFromFile("res/sp/main/heart.png", sfFalse);
    heart->sprite = sfSprite_create();
    sfSprite_setTexture(heart->sprite, heart->texture, sfFalse);
    heart->pos.x = 300;
    heart->pos.y = 300;
    sfSprite_setPosition(heart->sprite, heart->pos);
}

void init_template(st_main_menu *st)
{
    st->spp->size.x = 2000;
    st->spp->size.y = 1000;
    st->spp->origin1.x = 0;
    st->spp->origin1.y = 600;
    st->col->rect.a = 200;
    st->col->rect.r = 0;
    st->col->rect.g = 0;
    st->col->rect.b = 0;
    st->spp->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(st->spp->rect, st->spp->origin1);
    sfRectangleShape_setSize(st->spp->rect, st->spp->size);
    sfRectangleShape_setFillColor(st->spp->rect, st->col->rect);
    init_heart();
}