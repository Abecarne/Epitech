/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** init_variables
*/

#include "include/defender.h"

void init_pos2(st_def *st)
{
    sfVector2f scale = {3, 3};
    st->end.pdefeat.x = st->data.mode.width / 2 - 175;
    st->end.pdefeat.y = st->data.mode.height / 2 - 100;
    st->end.pvictory.x = st->data.mode.width / 2 - 150;
    st->end.pvictory.y = st->data.mode.height / 2 - 100;
    sfSprite_setScale(st->end.defeat, scale);
    sfSprite_setScale(st->end.victory, scale);
}

void init_pos(st_def *st)
{
    init_pos2(st);
    st->text.parag1pos.x = 300;
    st->text.parag1pos.y = 300;
    st->text.parag2pos.x = 300;
    st->text.parag2pos.y = 470;
    st->text.parag3pos.x = 510;
    st->text.parag3pos.y = 555;
    st->text.parag4pos.x = 450;
    st->text.parag4pos.y = 650;
    st->text.menupos.x = 100;
    st->text.menupos.y = st->data.mode.height / 2;
    st->text.titlepos.x = st->data.mode.width / 2 - 200;
    st->text.titlepos.y = 150;
    st->text.lifepos.x = st->data.mode.width - 60;
    st->text.lifepos.y = 45;
    st->text.pausepos.x = 50;
    st->text.pausepos.y = 60;
    st->text.sunpos.x = st->data.mode.width - 400;
    st->text.sunpos.y = 45;
}

void init_create(st_def *st)
{
    st->text.font = sfFont_createFromFile("font/Pixeled.ttf");
    st->text.menu = sfText_create();
    st->text.title = sfText_create();
    st->text.parag1 = sfText_create();
    st->text.parag2 = sfText_create();
    st->text.parag3 = sfText_create();
    st->text.parag4 = sfText_create();
    st->text.life = sfText_create();
    st->text.pause = sfText_create();
    st->text.sun = sfText_create();
    st->end.defeat = sfText_create();
    st->end.victory = sfText_create();
    sfText_setFont(st->text.menu, st->text.font);
    sfText_setFont(st->text.title, st->text.font);
    sfText_setFont(st->text.life, st->text.font);
    sfText_setFont(st->text.pause, st->text.font);
    sfText_setFont(st->text.sun, st->text.font);
    sfText_setFont(st->pause.resume, st->text.font);
    sfText_setFont(st->end.defeat, st->text.font);
    sfText_setFont(st->end.victory, st->text.font);
}

void init_txt(st_def *st)
{
    init_create(st);
    init_pos(st);
    sfText_setString(st->text.menu, "MENU");
    sfText_setString(st->text.title, "HOW TO PLAY");
    sfText_setString(st->text.life, "1");
    sfText_setString(st->text.pause, "PAUSE");
    sfText_setString(st->end.defeat, "DEFEAT");
    sfText_setString(st->end.victory, "VICTORY");
    sfText_setString(st->text.sun, int_to_char(st->icon.sunny));
    init_how(st);
    sfText_setPosition(st->text.menu, st->text.menupos);
    sfText_setPosition(st->text.title, st->text.titlepos);
    sfText_setPosition(st->text.life, st->text.lifepos);
    sfText_setPosition(st->text.pause, st->text.pausepos);
    sfText_setPosition(st->text.sun, st->text.sunpos);
    sfText_setPosition(st->end.defeat, st->end.pdefeat);
    sfText_setPosition(st->end.victory, st->end.pvictory);
}

void init_var(st_def *st)
{
    st->icon.sunny = 50;
    init_positions(st);
    init_rect_zomb(st);
    init_txt(st);
    init_color(st);
    init_clocks(st);
    init_rect_icons(st);
    st->win = 0;
    st->status = 0;
    st->nbs = 0;
    st->nbz.nb = 0;
    st->nbz.nb1 = 1;
    st->nbz.nb2 = 2;
    st->nbz.nb3 = 3;
    st->nbz.nb4 = 4;
    st->nbz.nb5 = 0;
}