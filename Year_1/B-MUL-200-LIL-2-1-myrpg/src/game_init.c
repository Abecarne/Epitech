/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "framing_engine.h"

int init_window(framing *lvl)
{
    char *title = "My RPG";
    sfVideoMode mode = {1824, 1056, 32};

    lvl->win = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(lvl->win, 32);
    return (0);
}

int game_init(int ac, char **av)
{
    framing lvl;
    input_manager input;
    int value = 0;

    if (init_lvl(&lvl) != 0 && init_window(&lvl) != 0
        && init_input(&input) != 0)
        return (my_put_error("Error: allocation failed\n"));
    if (game_loop(lvl, 0) != 0)
        my_put_error("Error: allocation failed\n");
    free_rpg(&lvl, &input);
    return (value);
}
