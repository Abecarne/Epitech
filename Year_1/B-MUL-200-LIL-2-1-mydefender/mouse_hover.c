/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** mouse_hover
*/

#include "include/defender.h"

int hover_play(st_def *st, sfSprite *sp)
{
    sfVector2i mouse = sfMouse_getPosition(st->data.wmain);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        st->rect.play.left = 286;
        sfSprite_setTextureRect(st->spm.play, st->rect.play);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->win = 1;
            return (1);
        }
    } else {
        st->rect.play.left = 0;
        sfSprite_setTextureRect(st->spm.play, st->rect.play);
    }
    return (0);
}

int hover_opt(st_def *st, sfSprite *sp)
{
    sfVector2i mouse = sfMouse_getPosition(st->data.wmain);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        st->rect.option.left = 286;
        sfSprite_setTextureRect(st->spm.option, st->rect.option);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->win = 4;
            return (1);
        }
    } else {
        st->rect.option.left = 0;
        sfSprite_setTextureRect(st->spm.option, st->rect.option);
    }
    return (0);
}

int hover_exit(st_def *st, sfSprite *sp)
{
    sfVector2i mouse = sfMouse_getPosition(st->data.wmain);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sp);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue) {
        st->rect.exit.left = 286;
        sfSprite_setTextureRect(st->spm.exit, st->rect.exit);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            st->status = -1;
            return (1);
        }
    } else {
        st->rect.exit.left = 0;
        sfSprite_setTextureRect(st->spm.exit, st->rect.exit);
    }
    return (0);
}

int hover_main(st_def *st, sfText *sp)
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

int hover_pause_game(st_def *st, sfText *sp)
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
            st->win = 2;
            return (1);
        }
    }
    return (0);
}