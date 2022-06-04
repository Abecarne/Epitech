/*
** EPITECH PROJECT, 2021
** delivery
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"
#include <stdlib.h>

int nb_word(char *str)
{
    int sp = 1;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            sp++;
    return (sp);
}

char **str_to_array(char *str)
{
    int i = 0;
    int j = 0;
    int ind = 0;
    char **res = malloc(sizeof(char *) * (nb_word(str) + 1));

    for (i; str[i] != '\0'; i++) {
        if (ind == 0) {
            res[j] = malloc(sizeof(char) * my_strlen(str) + 1);
        }
        if (str[i] == '\n') {
            res[j][ind] = str[i];
            res[j][ind + 1] = '\0';
            ind = 0;
            j++;
        } else {
            res[j][ind] = str[i];
            ind++;
        }
    }
    res[j] = NULL;
    return (res);
}