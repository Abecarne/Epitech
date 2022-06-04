/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** Fonction vide
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] <= 127)
            i++;
        else
            return (0);
    }
    return (1);
}
