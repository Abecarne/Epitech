/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_show_word_array
*/

#include <stdio.h>

int my_putstr(char const *str);

int  my_show_word_array(char * const *tab)
{
    int i = 0;
    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}