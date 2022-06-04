/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

char **create_tab(char *file, int nbl, int nbc)
{
    char **res = malloc(sizeof(char *) * (nbl + 1));
    for (int i = 0; i < nbl; i++) {
        res[i] = malloc(sizeof(char) * nbc + 2);
        for (int j = 0; j < nbc + 1; j++) {
            res[i][j] = file[i * nbc + j + i];
        }
        res[i][nbc] = '\n';
        res[i][nbc + 1] = '\0';
    }
    res[nbl] = NULL;
    return (res);
}

void print_tab(char *tab, int res, int size)
{
    int tmp = size;
    int nbc = nb_col(tab);

    for (int i = 0; tab[i] != 0; i++) {
        if (i >= res && tmp != 0) {
            for (int j = 0; j < size; j++)
                tab[i + j] = 'x';
            i += size - 1;
            tmp--;
            res += nbc + 1;
        }
    }
    my_putstr(tab);
}

int error_lign(char *str_nb, char *str, int nl)
{
    char nb[nb_col(str) + 1];

    for (int i = 0; str_nb[i] != '\0'; i++) {
        if (str_nb[i] != '.' && str_nb[i] != 'o' && str_nb[i] != '\n')
            exit (84);
    }
    for (int i = 0; str[i] != '\n'; i++) {
        nb[i] = str[i];
    }
    nb[nb_col(str)] = '\0';
    if (my_getnbr(nb) != nb_lign(str_nb)) {
        exit (84);
    }
}