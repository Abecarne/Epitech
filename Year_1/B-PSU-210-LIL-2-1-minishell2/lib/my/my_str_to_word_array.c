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

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            while (str[i] == ' ')
                    i++;
            sp++;
        }
    }
    return (sp);
}

char **str_to_array(char *str)
{
    char **res = malloc(sizeof(char *) * nb_word(str) + 1);
    int i = 0;
    int j = 0;
    int ind = 0;

    for (i; str[i] != '\0'; i++) {
        if (ind == 0) {
            res[j] = malloc(sizeof(char) * my_strlen(str));
        }
        if (str[i] == ':') {
            ind = 0;
            j++;
        } else {
            res[j][ind] = str[i];
            ind++;
        }
    }
    res[j + 1] = NULL;
    return (res);
}