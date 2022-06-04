/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday08-simon.auduberteau
** File description:
** my_show_word_array
*/
#include <stddef.h>
#include "my.h"

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}