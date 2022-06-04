/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** text
*/

#include "menu.h"

void init_text_menu(st_main_menu *st)
{
    st->text.font = sfFont_createFromFile("res/font/Pixeled.ttf");
    st->text.menu = sfText_create();
    st->text.play = sfText_create();
    sfText_setFont(st->text.menu, st->text.font);
    sfText_setFont(st->text.play, st->text.font);
    sfText_setString(st->text.menu, "BACK TO MAIN MENU");
    sfText_setString(st->text.play, "PLAY");
    st->text.menupos.x = st->data->mode.height / 2;
    st->text.menupos.y = st->data->mode.height * 0.3;
    st->text.playpos.x = 100;
    st->text.playpos.y = 100;
    sfText_setPosition(st->text.menu, st->text.menupos);
    sfText_setPosition(st->text.play, st->text.playpos);
}

void position_text(st_main_menu *st)
{
    sfVector2f scale = {2.3, 2.3};
    st->text.resumepos.x = st->data->mode.width / 2 - 200;
    st->text.resumepos.y = 150;
    st->text.inventorypos.x = st->data->mode.width / 2 - 268;
    st->text.inventorypos.y = 300;
    st->text.optionpos.x = st->data->mode.width / 2 - 185;
    st->text.optionpos.y = 450;
    st->text.exitpos.x = st->data->mode.width / 2 - 248;
    st->text.exitpos.y = 600;
    sfText_setScale(st->text.resume, scale);
    sfText_setScale(st->text.inventory, scale);
    sfText_setScale(st->text.option, scale);
    sfText_setScale(st->text.exit, scale);
    sfText_setPosition(st->text.resume, st->text.resumepos);
    sfText_setPosition(st->text.inventory, st->text.inventorypos);
    sfText_setPosition(st->text.option, st->text.optionpos);
    sfText_setPosition(st->text.exit, st->text.exitpos);
}

void init_combler_fond(st_main_menu *st)
{
    sfVector2f scale = {2.3, 2.3};
    st->text.trou = sfText_create();
    sfText_setFont(st->text.trou, st->text.font);
    sfText_setString(st->text.resume, "Press F for Fight\n");
    st->text.troupos.x = 0;
    st->text.troupos.y = 0;
    sfText_setPosition(st->text.trou, st->text.troupos);
    sfText_setScale(st->text.trou, scale);
}

void init_text_pause(st_main_menu *st)
{
    st->text.font = sfFont_createFromFile("res/font/Pixeled.ttf");
    st->text.resume = sfText_create();
    st->text.inventory = sfText_create();
    st->text.option = sfText_create();
    st->text.exit = sfText_create();
    sfText_setFont(st->text.resume, st->text.font);
    sfText_setFont(st->text.inventory, st->text.font);
    sfText_setFont(st->text.option, st->text.font);
    sfText_setFont(st->text.exit, st->text.font);
    sfText_setString(st->text.resume, "RESUME");
    sfText_setString(st->text.inventory, "INVENTORY");
    sfText_setString(st->text.option, "OPTION");
    sfText_setString(st->text.exit, "MAIN MENU");
    position_text(st);
    init_combler_fond(st);
}