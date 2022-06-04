/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_strcat
*/

char *my_strcat(char *dest , char  const *src)
{
    int a = my_strlen(dest);
    int i = 0;

    for (i; src[i] != '\0'; i++)
        dest[a + 1] = src[i];
    dest[a + 1] = '\0';
    return (dest);
}