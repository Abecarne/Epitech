/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday06-simon.auduberteau
** File description:
** my_strstr
*/
#include <stddef.h>

int my_strstrlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] != '\0') {
        for (int a = 0; to_find[a] != '\0'; a++) {
            if (to_find[a] != str[a]) {
                return (my_strstr(str + 1, to_find));
            }
        }
        return (str);
    }
    return (NULL);
}
