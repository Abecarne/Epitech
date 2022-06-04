/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** hover_pause_menu
*/

#include "menu.h"

int hover_attack(st_main_menu *st, sfText *sp)
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
            st->sc = 6;
            return (1);
        }
    }
    return (0);
}

int hover_skip_round(st_main_menu *st, sfText *sp)
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

int hover_runaway(st_main_menu *st, sfText *sp)
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

int hover_fight(st_main_menu *st)
{
    if (hover_attack(st, st->ftxt->attack) == 1)
        return (1);
    if (hover_skip_round(st, st->ftxt->skip) == 1)
        return (1);
    if (hover_runaway(st, st->ftxt->run) == 1)
        return (1);
    return (0);
}

int hover_select_attack(st_main_menu *st)
{
    if (hover_atk1(st, st->ftxt->atk1) == 1)
        return (1);
    if (hover_comp1(st, st->ftxt->comp1) == 1)
        return (1);
    if (hover_comp2(st, st->ftxt->comp2) == 1)
        return (1);
    return (0);
}