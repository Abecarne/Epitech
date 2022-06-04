/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday04-simon.auduberteau
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}