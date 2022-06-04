/*
** EPITECH PROJECT, 2020
** B-CPE-101-LIL-1-1-evalexpr-simon.auduberteau
** File description:
** replace_str_calc
*/

#include <stdlib.h>

int is_factor(char c);

int is_add(char c);

int my_spe_getnbr(char *str, int begin);

int my_spe_getnbr_end(char *str, int begin, int end);

int operators(int a, int c, char b);

char *factor(char *str);

int check_sign_op(char *dest);

char *sum(char *str);

char *summer(char *dest, char *ind_sum);

char *multiplicater(char *dest, char *ind_prio);

char *replace_dest_by_res(char *dest, char *calc, int res);

char *calc_to_char(int beg, int end, char *dest)
{
    char *tmp;
    int cpt = 0;
    int j = 0;

    for (int i = beg; i != end; i++)
        cpt++;
    tmp = malloc(sizeof(char) * cpt + 1);
    for (int i = beg; i != end; i++, j++)
        tmp[j] = dest[i];
    return (tmp);
}

int beginning(char *dest, int i, char *ind_prio, int j)
{
    for (i = (ind_prio[j] - 48) - 1; i != 0 ||
    is_factor(dest[i] != 1) || is_add(dest[i] != 1); i--) {
        if (i == 0 || dest[i] == '/' || dest[i] == '%' ||
        dest[i] == '*' || dest[i] == '+' || dest[i] == '-')
            break;
    }
    if (i == 0)
        return (i);
    else
        return (i + 1);
}

int final(char *dest, int k, char *ind_prio, int j)
{
    for (k = (ind_prio[j] - 48) + 1; dest[k] != '\0' ||
    is_factor(dest[k] != 1) || is_add(dest[k] != 1); k++) {
        if (dest[k] == '\0' || dest[k] == '/' || dest[k] == '%' ||
        dest[k] == '*' || dest[k] == '+' || dest[k] == '-')
            break;
    }
    return (k);
}

int contain_sign(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
            str[i] == '/' || str[i] == '%') {
            return (1);
        }
    }
    return (0);
}

char *result_calc(char *dest)
{
    char *ind_prio = factor(dest);
    char *ind_sum = sum(dest);

    dest = multiplicater(dest, ind_prio);
    ind_prio = factor(dest);
    if (ind_prio[0] == '\0') {
        ind_sum = sum(dest);
        dest = summer(dest, ind_sum);
    }
    return (dest);
}
