/*
** EPITECH PROJECT, 2020
** Anthony & Simon & Eliott
** File description:
** bistromatic
*/

#include "my.h"
#include <stdlib.h>

char *change_str(char *str, char *base, char const *ref)
{
    char *dest = malloc(sizeof(char) * my_strlen(str) + 1);
    dest = my_strcpy(dest, str);
    for (int i = 0; dest[i] != '\0'; i++) {
        for (int j = 0; base[j] != '\0'; j++) {
            if (str[i] == base[j]) {
                dest[i] = ref[j];
            }
        }
    }
    return (dest);
}
