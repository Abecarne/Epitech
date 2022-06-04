/*
** EPITECH PROJECT, 2020
** my_show_word_array.c
** File description:
** show word array
*/

#include "my.h"

int my_show_word_array(char * const *tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (i);
}
