/*
** EPITECH PROJECT, 2021
** B-MUL-200-LIL-2-1-myrpg-charly.le-corre
** File description:
** main
*/

#include "menu.h"
#include "my.h"

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-') {
        if (av[1][1] == 'h')
            help();
    } else {
        if (main_menu() == 84)
            return (84);
    }
    return (0);
}