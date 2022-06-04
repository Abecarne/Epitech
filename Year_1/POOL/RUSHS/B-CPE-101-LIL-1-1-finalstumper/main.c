/*
** EPITECH PROJECT, 2020
** Anthony Becarne & Alexandre Savreux
** File description:
** main.c
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 4096

int rush3(char *buff)
{
    int i = 0;
    int j = 0;

    for (i; buff[i] != '\n'; i++) {
    }
    for (int k = 0; buff[k] != '\0'; k++) {
        if (buff[k] == '\n')
            j++;
    }
    if (i == 1 || j == 1)
        return (size1(buff, i, j));
    if (i > 1 && j > 1)
        return (size2(buff, i, j));
    return (84);
}

void print(int k, int i, int j)
{
    my_putstr("[rush1-");
    my_put_nbr(k);
    my_putstr("] ");
    my_put_nbr(i);
    my_putchar(' ');
    my_put_nbr(j);
}

int main(void)
{
    char buff[BUFF_SIZE];
    int offset = 0;
    int len = 0;

    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    if (len < 0 || buff[0] == '\0') {
        write(2, "\e[34mnone\e[0m\n", 14);
        return (84);
    }
    if (rush3(buff) == 84) {
        write(2, "\e[34mnone\e[0m\n", 14);
        return (84);
    }
    return (0);
}
