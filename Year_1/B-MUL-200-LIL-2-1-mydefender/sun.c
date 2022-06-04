/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** sun
*/

#include "include/defender.h"

void disp_sun(st_def *st)
{
    change_sun(st);
    move_sun(st);
    sfRenderWindow_drawSprite(st->data.wmain, st->spg.sun, NULL);
}

void change_sun(st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(st->time.sun)) > 500) {
        if (st->nbs == 1) {
            st->rect.sun.left = 27;
            st->nbs = 0;
        } else {
            st->rect.sun.left = 0;
            st->nbs += 1;
        }
        sfSprite_setTextureRect(st->spg.sun, st->rect.sun);
        sfClock_restart(st->time.sun);
    }
}

void move_sun(st_def *st)
{
    if (sfTime_asMilliseconds(sfClock_getElapsedTime(st->time.ssun)) > 10) {
        if (st->posg.sun.y > 900)
            random_sun(st, st->spg.sun, 0);
        st->posg.sun.y += 0.75;
        sfSprite_setPosition(st->spg.sun, st->posg.sun);
        sfClock_restart(st->time.ssun);
    }
    if (click_sun(st, st->spg.sun) == 1) {
        st->icon.sunny += 50;
        sfText_setString(st->text.sun, int_to_char(st->icon.sunny));
        random_sun(st, st->spg.sun, 0);
    }
}

void random_sun(st_def *st, sfSprite *sp, int i)
{
    int minx = 100;
    int maxx = 1300;
    int miny = -500;
    int maxy = -100;

    rand();
    st->posg.sun.x = (rand() %  (maxx - minx) + 1) + minx;
    st->posg.sun.y = (rand() %  (maxy - miny) + 1) + miny;
    sfSprite_setPosition(st->spg.sun, st->posg.sun);
}

int click_sun(st_def *st, sfSprite *sun)
{
    sfVector2i mouse = sfMouse_getPosition(st->data.wmain);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sun);
    sfIntRect rect;
    rect.left = bounds.left;
    rect.height = bounds.height;
    rect.top = bounds.top;
    rect.width = bounds.width;

    if (sfIntRect_contains(&rect, mouse.x, mouse.y) == sfTrue)
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            return (1);
        }
    return (0);
}