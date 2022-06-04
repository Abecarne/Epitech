/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strncpy
*/
int my_strlen(char  const *str);

char *my_strncpy(char *dest , char  const *src, int n)
{   
    int i = 0;

    for (i; i < n; i++) {
        dest[i] = src[i];
    }
    if (my_strlen(src) < n) {
        dest[i] == '\0';
    }
    return (dest);
}
