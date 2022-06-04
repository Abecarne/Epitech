/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** array_1d_to_2d
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    int ind = 0;
    size_t i;
    size_t j;

    *res = malloc(sizeof(int *) * (height + 1));
    for (i = 0; i < height; i++) {
        (*res)[i] = malloc(sizeof(int) * (width + 1));
        for (j = 0; j < width; j++) {
            (*res)[i][j] = array[ind];
            ind++;
        }
    }
}

void array_2d_free(int **array, size_t height, size_t width)
{
    (void)width;

    for (size_t i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
