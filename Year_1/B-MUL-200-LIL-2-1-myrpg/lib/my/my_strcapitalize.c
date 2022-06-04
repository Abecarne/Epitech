/*
** EPITECH PROJECT, 2020
** my_strcapitalize.c
** File description:
** str capitalize
*/

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        if (i > 1 && (str[i - 1] == ' ' || str[i - 1] == '+'
            || str[i - 1] == '-') && str[i] <= 'z' && str[i] >= 'a')
            str[i] -= 32;
        if (i > 1 && str[i] <= 'Z' && str[i] >= 'A' && str[i - 1] != ' '
            && str[i - 1] != '+' && str[i - 1] != '-')
            str[i] += 32;
    }
    return (str);
}
