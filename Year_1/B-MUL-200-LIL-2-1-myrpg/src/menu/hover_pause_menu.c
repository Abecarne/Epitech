/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** hover_pause_menu
*/

#include "menu.h"

int hover_presume(st_main_menu *st, sfText *sp)
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

int hover_pinventory(st_main_menu *st, sfText *sp)
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

int hover_popt(st_main_menu *st, sfText *sp)
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
            st->sc = 4;
            return (1);
        }
    }
    return (0);
}

int hover_pexit(st_main_menu *st, sfText *sp)
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
            st->sc = 0;
            return (1);
        }
    }
    return (0);
}