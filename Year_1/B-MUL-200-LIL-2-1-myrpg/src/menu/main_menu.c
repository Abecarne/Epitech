/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** main_menu
*/

#include "menu.h"

int main_menu(void)
{
    st_main_menu *st = malloc(sizeof(st_main_menu));
    int (*scene[7])(st_main_menu *);

    scene[0] = &loop_menu;
    scene[1] = &loop_game;
    scene[2] = &loop_pause;
    scene[3] = &loop_end;
    scene[4] = &loop_option;
    scene[5] = &loop_fight;
    scene[6] = &loop_attack;
    malloc_struct(st);
    if (load_var(st) == 84)
        return (84);
    init_var(st);
    while (st->status != -1)
        scene[st->sc](st);
    free_all(st);
    return (0);
}