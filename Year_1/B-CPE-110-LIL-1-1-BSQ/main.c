/*
** EPITECH PROJECT, 2020
** delivery [WSL: fedora]
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "include/my.h"

void main(int ac, char **av)
{
    int op;
    char *cpy;
    char **str;
    struct stat file;

    op = open(av[1], O_RDONLY);
    if (op < 0 || ac != 2)
        exit (84);
    else {
        stat(av[1], &file);
        if (file.st_size == 0)
            exit (84);
        cpy = malloc(sizeof(char) * file.st_size + 1);
        read(op, cpy, file.st_size);
    }
    close(op);
    for (op = 0; cpy[op] != '.' && cpy[op] != 'o'; op++);
    error_lign(cpy + op, cpy, nb_lign(cpy + op));
    str = create_tab(cpy + op, nb_lign(cpy + op), nb_col(cpy + op));
    mainloop(str, cpy + op, nb_col(cpy + op), nb_lign(cpy + op));
    free(cpy);
}
