/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday06-simon.auduberteau
** File description:
** my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}