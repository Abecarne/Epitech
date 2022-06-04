/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** my_getnbr
*/

char my_getsigne(char const *str)
{
    int signe = 1;
    int count = 0;

    if (str[0] == '-' || str[0] == '+' || str[0] == '/' || (
        str[0] == '*') || str[0] == '%')
        return (str[0]);
    return (0);
}