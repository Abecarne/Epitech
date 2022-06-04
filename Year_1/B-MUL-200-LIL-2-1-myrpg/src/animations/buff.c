/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** buff
*/

#include "menu.h"

void buff_anim(st_main_menu *st)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    sfVector2f size = {20, 20};
    sfVector2f pos = {250, 250};

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setPosition(rect, pos);
    sfRenderWindow_drawRectangleShape(st->data->wmain, rect, NULL);
}