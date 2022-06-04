/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** Task 02
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *str1, char *str2)
{
    int i = 0;
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    char *ret = malloc(sizeof(char) * (len1 + len2) + 1);

    for (int j = 0; str1[j] != '\0'; j++)
        ret[j] = str1[j];
    for (int k = len1; str2[i] != '\0'; k++) {
        ret[k] = str2[i];
        i++;
    }
    return (ret);
}