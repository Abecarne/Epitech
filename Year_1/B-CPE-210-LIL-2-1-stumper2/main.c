/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Duo stumper 2
*/

#include "include/game.h"

int nb_neighbours(int x, int y, char **map)
{
    int count = 0;

    if (x > 0)
        for (int j = -1; j < 2; j++)
            if (check_null(x - 1, y + j, map) == 0 && map[x - 1][y + j] == 'X')
                count++;
    if (map[x + 1] != NULL)
        for (int j = -1; j < 2; j++)
            if (check_null(x + 1, y + j, map) == 0 && map[x + 1][y + j] == 'X')
                count++;
    if (y > 0 && map[x][y - 1] == 'X')
        count++;
    if (map[x][y + 1] != '\0' && map[x][y + 1] != '\n' && map[x][y + 1] == 'X')
        count++;
    return (count);
}

char **replace_actual(int x, int y, char **clear_map, char **map)
{
    int nb_neigh = nb_neighbours(x, y, clear_map);

    if (clear_map[x][y] == '.' && nb_neigh == 3)
        map[x][y] = 'X';
    if (clear_map[x][y] == 'X')
        if (nb_neigh < 2 || nb_neigh > 3)
            map[x][y] = '.';
    return (map);
}

char **gameloop(char **clear_map, char **map)
{
    for (int x = 0; clear_map[x] != NULL; x++) {
        for (int y = 0; clear_map[x][y] != '\0'
        && clear_map[x][y] != '\n'; y++) {
            map = replace_actual(x, y, clear_map, map);
        }
    }
    return (map);
}

int main(int ac, char **av)
{
    char **map = NULL;
    char **clear_map = NULL;

    map = error_handling(ac, av, map);
    for (int i = 0; i < my_getnbr(av[2]); i++) {
        clear_map = my_tabcpy(map);
        map = gameloop(clear_map, map);
        free_all(clear_map);
    }
    my_put_tab(map);
    free_all(map);
    return (0);
}