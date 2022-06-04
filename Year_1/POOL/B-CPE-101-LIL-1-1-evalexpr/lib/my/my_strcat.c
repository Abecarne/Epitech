/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** project
*/

int my_strlen(char *);

char *my_strcat(char *dest, char const *src)
{
    int a;
    int i;
    a = my_strlen(dest);
    for (i = 0; src[i] != '\0'; i++){
        dest[a + i] = src[i];
    }
    dest[a + i] = '\0';
    return (dest);
}