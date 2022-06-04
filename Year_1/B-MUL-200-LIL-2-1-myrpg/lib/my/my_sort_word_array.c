/*
** EPITECH PROJECT, 2020
** my_sort_word_array.c
** File description:
** sort word in array
*/

#include "include/my.h"

char **update_tab(char **tab, int destination, int max, int size)
{
    int save_pos = 0;
    char *save_char = 0;

    for (int i = size - 1; i >= destination; i--) {
        if (tab[i][0] < max) {
            max = tab[i][0];
            save_pos = i;
        }
        if (tab[i][0] == max && my_strcmp(tab[i], tab[save_pos]) < 0)
            save_pos = i;
    }
    save_char = tab[save_pos];
    tab[save_pos] = tab[destination];
    tab[destination] = save_char;
    return (tab);
}

int my_sort_word_array(char **tab)
{
    int size = 0;
    int max = 127;

    for (; tab[size] != NULL; size++);
    for (int destination = 0; destination < size; destination++)
        tab = update_tab(tab, destination, max, size);
    return (0);
}
