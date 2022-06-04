/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_putstr
*/

int my_strlen(char const *str);

int  my_putstr(char const *str)
{
    write (1, str, my_strlen(str));
}
