/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** fight_launch
*/

#include "menu.h"

int enemi_inbound(st_main_menu *st)
{
    st->a = 0;
    if (sfKeyboard_isKeyPressed(sfKeyF)) {
        return (0);
    }
    return (1);
}