/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** uniq
*/
#include <stddef.h>
#include <stdio.h>

int my_pop_elem(int **array, int nmemb, int ind)
{
    for (int i = ind - 1; i < nmemb - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }
    return (nmemb - 1);
}


size_t uniq_int_array(int *array, size_t nmemb)
{
    size_t res = nmemb;

    for (size_t i = 0; i < res; i++) {
        for (size_t j = i + 1; j < res; j++) {
            if (array[i] == array[j]) {
                res = my_pop_elem(&array, res, j);
                i--;
            }
        }
    }
    return (res);
}