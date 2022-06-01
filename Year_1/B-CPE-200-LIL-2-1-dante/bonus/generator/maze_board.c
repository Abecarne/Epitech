/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** maze_board
*/

#include "../include/generator.h"

void print_map(st_generator *st)
{
    for (int i = 0; i < st->height; i++) {
        for (int j = 0; j < st->width; j++) {
            if (st->map[i][j] == 1)
                printf("#");
            if (st->map[i][j] == 0)
                printf(".");
        }
        if (i == st->height - 1)
            break;
        else
            printf("\n");
    }
}

int **malloc_map(int **map, int width, int height)
{
    int i;
    int j;

    map = malloc(sizeof(int *) * height);
    for (i = 0; i < height; i++) {
        map[i] = malloc(sizeof(int) * width);
        for (j = 0; j < width; j++)
            map[i][j] = 1;
    }
    return (map);
}
