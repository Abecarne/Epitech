/*
** EPITECH PROJECT, 2021
** abecarne
** File description:
** fight_hover2
*/

#include "menu.h"

int hover_atk1(st_main_menu *st, sfText *sp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(st->data->wmain);
    sfFloatRect bounds = sfText_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            charge_anim(st, st->spp->dos, st->spp->ennemi);
            return (1);
        }
    }
    return (0);
}

int hover_comp1(st_main_menu *st, sfText *sp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(st->data->wmain);
    sfFloatRect bounds = sfText_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->sc = 1;
            return (1);
        }
    }
    return (0);
}

int hover_comp2(st_main_menu *st, sfText *sp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(st->data->wmain);
    sfFloatRect bounds = sfText_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            buff_anim(st);
            return (1);
        }
    }
    return (0);
}