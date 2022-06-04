/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_str_isalpha
*/

int  my_str_isalpha(char  const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')) {
        return (1);
    }
    return (0);
}
}