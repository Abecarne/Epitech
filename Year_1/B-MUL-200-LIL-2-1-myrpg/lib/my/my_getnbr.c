/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** get nbr
*/

int count_minus(char const *str)
{
    int count = 0;
    int num = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= '9' && str[i] >= '0')
            num++;
        if (str[i] == '-' && num == 0)
            count++;
    }
    return (count);
}

int is_num(char c)
{
    if (c <= '9' && c >= '0')
        return (1);
    return (0);
}

int check_max_verif(char const *str, int min)
{
    int val = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0' && count != 9; i++) {
        if (is_num(str[i]) == 1) {
            val = val * 10 + (str[i] - 48);
            count++;
        }
        if (is_num(str[i]) != 1) {
            count = 0;
            val = 0;
        }
        if (count == 9 && val > 214748364)
            return (10);
        if (count == 9 && val == 214748364 && ((str[i + 1] > '7'
            && min % 2 == 0) || (str[i + 1] > '8' && min % 2 == 1)))
            return (10);
    }
    return (0);
}

int check_max(char const *str, int minus)
{
    int count = 0;

    for (int i = 0; str[i] != '\0' && (is_num(str[i]) == 1 || ((str[i] == '-'
        || str[i] == '+') && count == 0)) && count <= 10; i++) {
        if (str[i] <= '9' && str[i] >= '0')
            count++;
    }
    if (count > 10)
        return (10);
    if (count == 10)
        return (check_max_verif(str, minus));
    return (0);
}

int my_getnbr(char const *str)
{
    int minus = count_minus(str);
    int value = 0;
    int error = check_max(str, minus);
    int nbr = 0;
    int count = 0;

    if (error == 10)
        return (0);
    for (int i = 0; str[i] != '\0' && (is_num(str[i]) == 1 || ((str[i] == '-'
        || str[i] == '+') && count == 0)); i++) {
        if (is_num(str[i]) == 1) {
            nbr = str[i] - 48;
            value = (value * 10) + nbr;
            count++;
        }
    }
    if (minus % 2 == 1 && minus != 0)
        value = value * -1;
    return (value);
}
