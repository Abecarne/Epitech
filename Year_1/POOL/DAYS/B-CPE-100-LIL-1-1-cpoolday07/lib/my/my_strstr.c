/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strstr
*/
#include <stddef.h>

int my_strlen_strstr(char  const *str)
{
    int cpt = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        cpt++;
    }
    return (cpt);
}

char *my_strstr(char *str , char  const *to_find)
{
    int same = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; j < my_strlen_strstr(to_find); j++) {
            if (str[i + j] == to_find[j]) {
                same += 1;
            } else {
                same = 0;
            }
        }
        if (same == my_strlen_strstr(to_find)) {
            return (&str[i]);
        } 
        
        
    }
    return (NULL);
}