/*
** EPITECH PROJECT, 2020
** B-MUL-100-LIL-1-1-myhunter-simon.auduberteau
** File description:
** long_to_char
*/

char *my_revstr(char *str);

char *long_to_char(long nb, char *res)
{
    long integer = nb;
    double comma = nb;
    float tmp = 0;
    int i = 0;

    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
        return (res);
    }
    for (;integer != 0; i++) {
        tmp =  (((comma/10) - (integer/10)) * 10);
        integer /= 10;
        comma = integer;
        res[i] = ((int)(tmp+0.100) + '0');
    }
    res[i] = '\0';
    res = my_revstr(res);
    return (res);
}