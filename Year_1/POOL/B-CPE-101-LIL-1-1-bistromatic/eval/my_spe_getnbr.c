/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-evalexpr-simon.auduberteau
** File description:
** my_spe_getnbr
*/

int my_spe_getnbr_end(char *str, int begin, int end)
{
    int nb = 0;
    int a = 1;
    int i = begin;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            a *= -1;
    }
    while (str[i] != '\0' || i != end) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
            i++;
        } else
            return (nb * a);
    }
    return (nb * a);
}

int my_spe_getnbr(char *str, int begin)
{
    int nb = 0;
    int a = 1;
    int i = begin;

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