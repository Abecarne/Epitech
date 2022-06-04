/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** main
*/

#include "../include/main.h"

int main(int ac, char **av)
{
    datas_t *datas = malloc(sizeof(datas_t));

    if (error(ac, av) == 1)
        return (84);
    if (help(ac, av) == 0)
        return (0);
    if (init_datas(datas, av) == 84)
        return (84);
    if (server_ftp(datas) == 84) {
        free_datas(datas);
        return (84);
    }
    free_datas(datas);
    return (0);
}
