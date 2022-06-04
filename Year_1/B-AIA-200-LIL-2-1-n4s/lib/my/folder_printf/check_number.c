/*
** EPITECH PROJECT, 2020
** B-PSU-100-LIL-1-1-myprintf-simon.auduberteau
** File description:
** check_number
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
void my_putchar(char c);
int my_getnbr(char *str);
void print_nb_wlen(int nb);

void my_spe_putstr(char const *str, int nb)
{
    for (int i = 0; str[i] != nb; i++)
        my_putchar(str[i]);
}

int check_number(char *s, int i)
{
    char *tmp = malloc(sizeof(char) * 100);
    int k = 0;
    int j = i + 1;

    for (; s[j] >= '0' && s[j] <= '9'; j++, k++)
        tmp[k] = s[j];
    if (tmp[0] == '\0') {
        free(tmp);
        return (1);
    }
    if (s[j] != 's' || s[j] != 'd')
        return (1);
    free(tmp);
    return (0);
}

void print_output(va_list list, char *s, int i)
{
    char *tmp = malloc(sizeof(char) * 100);
    int k = 0;
    int j = i + 1;

    for (; s[j] >= '0' && s[j] <= '9'; j++, k++)
        tmp[k] = s[j];
    if (s[j] == 's')
        my_spe_putstr(va_arg(list, char *), my_getnbr(tmp));
    free(tmp);
}