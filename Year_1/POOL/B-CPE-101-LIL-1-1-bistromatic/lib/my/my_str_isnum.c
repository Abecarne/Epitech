/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_str_isnum
*/

int  my_str_isnum(char  const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= '0' || str[i] >= '9') {
            return (0);
        }
    }
    return (0);
}