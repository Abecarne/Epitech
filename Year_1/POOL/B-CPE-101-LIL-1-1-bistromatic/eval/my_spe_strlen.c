/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-evalexpr-simon.auduberteau
** File description:
** my_spe_strlen
*/

int my_spe_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if ((str[i] != '/' && str[i] != '%' && str[i] != '*' &&
            str[i] != '+' && str[i] != '-') && (str[i] < '0' && str[i] >'9'))
        break;
    }
    return (i);
}