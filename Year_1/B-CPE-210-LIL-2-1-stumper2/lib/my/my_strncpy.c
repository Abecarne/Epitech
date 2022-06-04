/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** Task 02
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int length = 0;
    int i = 0;

    while (src[length] != '\0')
        ++length;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    if (n > length) {
        dest[i] = '\0';
    }
    return (dest);
}
