/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** Duo stumper 2
*/

#include "include/game.h"

bool is_intarg(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (false);
    return (true);
}

int check_null(int x, int y, char **map)
{
    if (x < 0 || y < 0)
        return (1);
    else if (map[x][y] == '\n' || map[x][y] == '\0')
        return (1);
    else
        return (0);
}

void free_all(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
}

char **error_handling(int ac, char **av, char **map)
{
    if (ac != 3) {
        my_putstr_error("Error : wrong arguments.\n");
        exit(84);
    } else if (is_intarg(av[2]) == false) {
        my_putstr_error("Error : generations must be a positive number\n");
        exit(84);
    } else {
        map = get_map_from_file(av[1]);
        if (map == NULL)
            exit(84);
    }
    return (map);
}