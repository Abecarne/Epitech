/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** my_strlen
*/

void my_putchar(char c);

int my_strlen(char const *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nb++;
    return (nb);
}