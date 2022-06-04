/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** project
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int a;
    int i;
    a = my_strlen(dest);
    for (i = 0; i != nb; i++){
        dest[a + i] = src[i];
    }
    dest[a + i] = '\0';
    return (dest);
}
