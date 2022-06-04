/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** libmy
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;
    int length_src = my_strlen(src);

    str = malloc(sizeof(char) * (length_src + 1));
    while (src[i] != '\0') {
        str[i] = src[i];
        ++i;
    }
    str[i] = '\0';
    return (str);
}

char *my_strupcase(char *str)
{
    str = my_strdup(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
    return (str);
}
