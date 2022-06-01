/*
** EPITECH PROJECT, 2021
** generator
** File description:
** main
*/

#include "../include/generator.h"

int is_intarg(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}

void init_var(st_generator *st)
{
    st->width =  0;
    st->height = 0;
    st->x = 0;
    st->y = 0;
    st->x1 = 0;
    st->y1 = 0;
    st->dx = 0;
    st->dy = 0;
    st->x2 = 0;
    st->y2 = 0;
    st->map = NULL;
}

void free_var(st_generator *st)
{
    for (int i = 0; i < st->height; i++) {
        free(st->map[i]);
    }
    free(st->map);
}

void perfect_maze(st_generator *st, int ac, char **av)
{
    if (atoi(av[2]) % 2 == 1) {
        if (ac == 4 && (strcmp(av[3], "perfect") == 0)) {
            st->map[st->height - 2][st->width - 1] = 0;
        }
        else {
            st->map[st->height - 2][st->width - 1] = 0;
            st->map[st->height - 1][st->width - 2] = 0;
        }
    } else {
        if (ac == 4 && (strcmp(av[3], "perfect") == 0)) {
            st->map[st->height - 2][st->width - 1] = 0;
        }
        else {
            st->map[st->height - 2][st->width - 1] = 0;
            st->map[st->height - 1][st->width - 2] = 0;
        }
    }
}

int main(int ac, char **av)
{
    struct generator *st = malloc(sizeof(st_generator));

    if (ac != 3 && ac != 4)
        return (84);
    else if (is_intarg(av[1]) != 1 || is_intarg(av[2]) != 1)
        return (84);
    else {
        init_var(st);
        st->width =  my_getnbr(av[1]);
        st->height = my_getnbr(av[2]);
        maze(st);
        perfect_maze(st, ac, av);
        print_map(st);
    }
    free_var(st);
    return (0);
}
