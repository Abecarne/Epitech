/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** libmy
*/

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
            i++;
        else
            return (0);
    }
    return (1);
}
