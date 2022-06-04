/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** libmy
*/

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57)
            i++;
        else
            return (0);
    }
    return (1);
}
