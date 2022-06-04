/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_putstr
*/

int  my_putstr(char  const *str)
{
    for (int i = 0; str[i] !='\0'; i++) {
        my_putchar(str[i]);
    }
}
