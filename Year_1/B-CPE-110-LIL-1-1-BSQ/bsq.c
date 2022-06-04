/*
** EPITECH PROJECT, 2020
** delivery [WSL: fedora]
** File description:
** bsq
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

int nb_lign(char *file)
{
    int cpt = 0;

    for (int i = 0; file[i] != '\0'; i++) {
        if (file[i] == '\n') {
            cpt++;
        }
    }
    return (cpt);
}

int nb_col(char *file)
{
    int i = 0;

    while (file[i] != '\n')
        i++;
    return (i);
}

int checknum(char **str, int size, int col, int ln, int lnmax)
{
    for (int l = ln; l < ln + size; l++) {
        if (l == lnmax)
            return (1);
        for (int c = col; c < col + size; c++) {
            if (str[l][c] == 'o' || str[l][c] == '\n') {
                return (1);
            }
        }
    }
    return (0);
}

void mainloop(char **str, char *cpy, int col, int ln)
{
    int *res = malloc(sizeof(int) * (ln + 2));

    for (int i = 0; i < ln; i++)
        res[i] = -1;
    res[ln + 1] = -1;
    for (int l = 0; l < ln; l++) {
        for (int c = 0; c < col; c++) {
            for (int size = 1; checknum(str, size, c, l, ln) == 0; size++)
                res[size - 1] = (res[size - 1] == -1 ? l * col + l + c : res[size - 1]);
        }
    }
    int i = 0; 
    while (res[i] != -1)
        i++;
    print_tab(cpy, res[i - 1], i);
}