/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** my_getnbr
*/

int look_error2(int nb, int next, int sauvegarde, int signe)
{
    if (nb == 214748364 && next == '7')
            return (84);
        else if ((nb / 10 != sauvegarde) && nb != -2147483647)
            return (84);
    return (0);
}

int look_error(int nb, int next, int sauvegarde, int signe)
{
    if (signe == -1) {
        if (nb == 214748364 && next == '8')
            return (84);
        else if ((nb / 10 != sauvegarde) && nb != -2147483648)
            return (84);
    }
    if (signe == 1)
        return (look_error2(nb, next, sauvegarde, signe));
    return (0);
}

int take_number(int i, char const *str, int nb, int signe)
{
    int sauvegarde = 0;

    for (int j = i; str[j] <= '9' && str[j] >= '0'; j++) {
        sauvegarde = nb;
        nb = nb * 10 + (str[j] - 48);
        if (look_error(nb, str[j] - 48, sauvegarde, signe) == 84)
            return (0);
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    int signe = 1;
    int nb = 0;
    int test = 0;

    for (int i = 0; str[i] <= '9' || str[i] >= '0' && (
        str[i] == '-' && str[i] == '+'); i++) {
        if (str[i] == '-')
            signe = signe * -1;
        if (str[i] == '+')
            signe = signe * 1;
        if (str[i] <= '9' && str[i] >= '0') {
            nb = take_number(i, str, nb, signe);
            test = nb;
            return (test);
        }
    }
    return (0);
}