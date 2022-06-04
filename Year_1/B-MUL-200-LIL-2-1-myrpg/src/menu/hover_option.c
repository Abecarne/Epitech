/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** hover_option
*/

#include "menu.h"

int hover_oopt(st_main_menu *st, sfText *sp)
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

int hover_oplay(st_main_menu *st, sfText *sp)
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