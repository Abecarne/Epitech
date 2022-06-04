/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** how_to_play
*/

#include "include/defender.h"

void init_color(st_def *st)
{
    st->col.main.a = 255;
    st->col.main.r = 255;
    st->col.main.g = 255;
    st->col.main.b = 255;
    sfSprite_setColor(st->spm.fond, st->col.main);
    st->col.sun.a = 210;
    st->col.sun.r = 255;
    st->col.sun.g = 255;
    st->col.sun.b = 255;
    sfSprite_setColor(st->spg.sun, st->col.sun);
}

void init_how(st_def *st)
{
    char *str1 = "Your house is attacked by zombies.\nDefend it wite plants.";
    char *str2 = "Click on for choose the type and choose one place\none the";
    char *str3 = "garden to plant it.";
    char *str4 = "If one zombie arrives at your house\n            ITS LOST !";
    sfText_setFont(st->text.parag1, st->text.font);
    sfText_setFont(st->text.parag2, st->text.font);
    sfText_setFont(st->text.parag3, st->text.font);
    sfText_setFont(st->text.parag4, st->text.font);
    sfText_setString(st->text.parag1, str1);
    sfText_setString(st->text.parag2, str2);
    sfText_setString(st->text.parag3, str3);
    sfText_setString(st->text.parag4, str4);
    sfText_setPosition(st->text.parag1, st->text.parag1pos);
    sfText_setPosition(st->text.parag2, st->text.parag2pos);
    sfText_setPosition(st->text.parag3, st->text.parag3pos);
    sfText_setPosition(st->text.parag4, st->text.parag4pos);
}