/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday04-simon.auduberteau
** File description:
** my_getnbr
*/

int my_getnbr(char *str)
{
    int nb = 0;
    int a = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            a *= -1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        } else
            return (nb * a);
    }
    return (nb * a);
}