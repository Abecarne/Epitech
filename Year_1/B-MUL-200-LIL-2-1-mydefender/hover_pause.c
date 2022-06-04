/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** hover_pause
*/

#include "include/defender.h"

int hover_resume(st_def *st, sfText *sp)
{
    sfVector2i mouse = sfMouse_getPosition(st->data.wmain);
    sfFloatRect bounds = sfText_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->win = 1;
            return (1);
        }
    return (0);
}

int hover_back_main(st_def *st, sfText *sp)
{
    sfVector2i mouse = sfMouse_getPosition(st->data.wmain);
    sfFloatRect bounds = sfText_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->win = 0;
            return (1);
        }
    }
    return (0);
}

int hover_exit_pause(st_def *st, sfText *sp)
{
    sfVector2i mouse = sfMouse_getPosition(st->data.wmain);
    sfFloatRect bounds = sfText_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->status = -1;
            return (1);
        }
    }
    return (0);
}