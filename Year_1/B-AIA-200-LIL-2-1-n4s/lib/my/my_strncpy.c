/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday06-simon.auduberteau
** File description:
** my_strncpy
*/

int my_cpy_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

char *my_strncpy(char *dest , char  const *src , int n)
{
    int i = 0;
    int len_src = my_cpy_strlen(src);

    for (; i != n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return (dest);
}