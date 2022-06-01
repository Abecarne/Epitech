/*
** EPITECH PROJECT, 2021
** B-CPE-200-LIL-2-1-dante-anthony.becarne [WSL: Ubuntu-20.04]
** File description:
** load_map
*/

#include "../include/solver.h"

int recup_map(char **av, st_solver *st)
{
    int op = 0;
    struct stat file;

    op = open(av[1], O_RDONLY);
    if (op < 0)
        return (84);
    else {
        stat(av[1], &file);
        if (file.st_size == 0) {
            close(op);
            return (84);
        }
        st->file = malloc(sizeof(char) * file.st_size + 1);
        read(op, st->file, file.st_size);
        st->file[file.st_size] = '\0';
    }
    close(op);
    return (0);
}

int colum(st_solver *st)
{
    int i = 0;

    st->column = 0;
    for (int z  = 0, r = 0; st->file[z] != 0; z++) {
        for (r = 0 ;st->file[z] != '\n' && st->file[z] != 0; r++, z++);
        if (r > i)
            i = r;
    }
    st->column = i;
    return (i);
}

void line(st_solver *st)
{
    st->line = 0;
    for (int i = 0; st->file[i] != '\0'; i++) {
        if (st->file[i] == '\n')
            st->line++;
    }
    st->line++;
}

void map_board(st_solver *st)
{
    int j = 0;

    line(st);
    colum(st);
    st->map = malloc(sizeof(char *) * (st->line + 1));
    for (int i = 0, index = 0; st->file[i] != '\0'; i++) {
        if (index == 0)
            st->map[j] = malloc(sizeof(char) * my_strlen(st->file));
        if (st->file[i] == '\n') {
            st->map[j][index] = '\0';
            index = 0;
            j++;
        } else {
            st->map[j][index] = st->file[i];
            index++;
        }
    }
    st->map[j + 1] = NULL;
}

void copy_map_int(st_solver *st)
{
    st->int_map = malloc(sizeof(int *) * (st->line + 1));
    for (int i = 0; i < st->line; i++) {
        st->int_map[i] = malloc(sizeof(int) * st->column + 1);
        for (int j = 0; j < st->column; j++) {
            if (st->map[i][j] == '*')
                st->int_map[i][j] = 0;
            else
                st->int_map[i][j] = 1;
        }
    }
}