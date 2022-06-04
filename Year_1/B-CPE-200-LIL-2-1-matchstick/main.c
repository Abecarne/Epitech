/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** main
*/

#include "include/matchstick.h"

int is_intarg(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    else if ((is_intarg(av[1]) != 1) || (is_intarg(av[2]) != 1))
        return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) > 100)
        return (84);
    if (my_getnbr(av[2]) <= 0)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    st_match *st = malloc(sizeof(st_match));
    st->player = malloc(sizeof(st_player));
    st->bot = malloc(sizeof(st_ai));

    if (error(ac, av) == 84)
        return (84);
    init_struct(av, st);
    array_stick(st);
    gameloop(st);
    if (st->win != 0)
        print_tab(st->board);
    free_all(st);
    return (print_end(st));
}