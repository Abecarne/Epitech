/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "framing_engine.h"

int game_loop(framing *lvl, int src)
{
    lvl->next = -1;
    lvl->selected_map = src;
    if (load_map(lvl, src) != 0)
        return (84);
    while (sfRenderWindow_isOpen(lvl->win) && lvl->next == -1) {
        sfRenderWindow_display(lvl->win);
        input_manager(lvl);
        close_window(lvl->win, def);
    }
    if (lvl->next != 0)
        game_loop(lvl, lvl->next);
    return (0);
}
