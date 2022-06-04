/*
** EPITECH PROJECT, 2020
** projets
** File description:
** main
*/
#include "include/struct.h"
#include "include/my.h"

global_t var;

void load(void)
{
    textures();
    sprites();
    sprites2();
    sprites3();
    music();
    positions();
    clocks();
    texts();
    var.change_per = 1;
    var.change_mob = 0;
}

int main(int ac, char **av)
{
    if (ac == 1) {
        my_printf("./my_runner: bad arguments: 0 given but 1 is required\n");
        my_printf("retry with -h\n");
        return (84);
    }
    if (ac == 2 && av[1][0] == '-') {
        if (av[1][1] == 'h')
            help();
    } else if (ac == 2) {
        load();
        open_window();
    } else
        return (84);
    return (0);
}