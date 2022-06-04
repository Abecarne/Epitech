/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** sort
*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void my_swap_index(int *array, int i, int j)
{
    int tmp;

    if (array[i] > array[j]) {
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
}

void sort_int_array(int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++) {
        for (size_t j = i + 1; j < nmemb; j++) {
            my_swap_index(array, i, j);
        }
    }
}

void sort_array(void *array, size_t nmemb, size_t size,
                int (* compar)(const void *, const void *))
{
    qsort(array, nmemb, size, compar);
}
