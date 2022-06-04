/*
** EPITECH PROJECT, 2020
** input_manager.c
** File description:
** input manager
*/

#include "my.h"
#include "framing_engine.h"

int input_manager(framing *lvl)
{
    int i = 0;
    int (*func[4])(framing *lvl) = {go_up, go_down, go_left, go_right};
    sfKeyCode arg[4] = {sfKeyLeft, sfKeyRight, sfKeyUp, sfKeyDown};

    if (lvl->annim != 0)
        return (1);
    for (; i < 4; i++)
        if (sfMouse_isButtonPressed(arg[i]))
            func[i](lvl);
    if (i == 4)
        lvl->pressed = 0;
    return (0);
}
