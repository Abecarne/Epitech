/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday04-simon.auduberteau
** File description:
** my_putstr
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}