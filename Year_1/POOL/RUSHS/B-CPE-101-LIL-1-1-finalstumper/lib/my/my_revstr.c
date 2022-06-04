/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** my_revstr
*/

char *my_revstr(char *str)
{
    int x = 0;
    char c;

    for (int i = 0; str[i] != '\0'; i++)
        x++;
    x = x - 1;
    for (int i = 0; i < x; i++) {
        c = str[x];
        str[x] = str[i];
        str[i] = c;
        x--;
    }
    return (str);
}