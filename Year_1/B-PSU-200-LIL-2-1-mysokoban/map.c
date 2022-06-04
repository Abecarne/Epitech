/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** map
*/

#include "sokoban.h"

void cpt_lignmax(var_t *st)
{
    for (int i = 0; st->file[i] != '\0'; i++)
        if (st->file[i] == '\n')
            st->nbl++;
}

void cpt_colmax(var_t *st)
{
    int j = 0;

    for (int i = 0; st->file[i] != '\0'; i++) {
        if (st->file[i] == '\n') {
            if (j > st->nbc)
                st->nbc = j;
            j = 0;
        } else {
            j++;
        }
    }
}

void recup_map(char **av, var_t *st)
{
    int op = 0;
    struct stat file;

    op = open(av[1], O_RDONLY);
    if (op < 0)
        exit (84);
    else {
        stat(av[1], &file);
        if (file.st_size == 0)
            exit (84);
        st->file = malloc(sizeof(char) * file.st_size + 1);
        read(op, st->file, file.st_size);
        st->file[file.st_size] = '\0';
    }
    close(op);
    st->map = str_to_array(st->file);
}

void load_map(char **av, var_t *st)
{
    recup_map(av, st);
    cpt_lignmax(st);
    cpt_colmax(st);
    error(st);
}