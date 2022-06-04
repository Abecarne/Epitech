/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** hover_main_menu
*/

#include "menu.h"

int hover_play(st_main_menu *st, sfSprite *sp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(st->data->wmain);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        st->rect->play.left = 286;
        sfSprite_setTextureRect(st->spm->play, st->rect->play);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->sc = 1;
            return (1);
        }
    } else {
        st->rect->play.left = 0;
        sfSprite_setTextureRect(st->spm->play, st->rect->play);
    }
    return (0);
}

int hover_opt(st_main_menu *st, sfSprite *sp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(st->data->wmain);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        st->rect->option.left = 286;
        sfSprite_setTextureRect(st->spm->option, st->rect->option);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->sc = 4;
            return (1);
        }
    } else {
        st->rect->option.left = 0;
        sfSprite_setTextureRect(st->spm->option, st->rect->option);
    }
    return (0);
}

int hover_exit(st_main_menu *st, sfSprite *sp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(st->data->wmain);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        st->rect->exit.left = 286;
        sfSprite_setTextureRect(st->spm->exit, st->rect->exit);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->status = -1;
            return (1);
        }
    } else {
        st->rect->exit.left = 0;
        sfSprite_setTextureRect(st->spm->exit, st->rect->exit);
    }
    return (0);
}