/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** main
*/

#include "include/defender.h"

void init_window(st_def *st)
{
    st->data.mode.width = 1600;
    st->data.mode.height = 900;
    st->data.wmain = sfRenderWindow_create(st->data.mode, st->name,
                                                    sfClose, NULL);
    sfWindow_setFramerateLimit(st->data.wmain, 120);
}

int main(int ac, char **av)
{
    st_def *st = malloc(sizeof(st_def));
    int (*scene[5])(st_def *);

    scene[0] = &loop_menu;
    scene[1] = &loop_game;
    scene[2] = &loop_pause;
    scene[3] = &loop_end;
    scene[4] = &loop_option;
    if (ac == 2 && av[1][0] == '-') {
        if (av[1][1] == 'h')
            help();
        return (0);
    } else {
        if (load_var(st) == 84)
            return (84);
        init_window(st);
        while (st->status != -1)
            scene[st->win](st);
    }
    free_all(st);
    return (0);
}