/*
** EPITECH PROJECT, 2020
** my_str_isnum.c
** File description:
** is num
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > '9' || str[i] < '1')
            return (0);
    return (1);
}
