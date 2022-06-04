/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strcpy
*/

int my_strlen(char  const *str);

char *my_strcpy(char *dest , char  const *src)
{
    int i = 0;
    for (i; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
