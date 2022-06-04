/*
** EPITECH PROJECT, 2020
** Anthony Becarne & Alexandre Savreux
** File description:
** final
*/
#include "my.h"

int size1(char *buff, int i, int j)
{
    if (buff[0] == 'o') {
        print(1, i, j);
        my_putchar('\n');
        return (0);
    }
    if (buff[0] == '*') {
        print(2, i, j);
        my_putchar('\n');
        return (0);
    }
    if (buff[0] == 'B') {
        print(3, i, j);
        my_putstr(" || ");
        print(4, i, j);
        my_putstr(" || ");
        print(5, i, j);
        my_putchar('\n');
        return (0);
    }
    return (84);
}

int size3part2(char *buff, int i, int j, int k)
{
    if (buff[k] == 'A') {
        print(4, i, j);
        my_putchar('\n');
        return (0);
    }
    if (buff[k] == 'C') {
        print(5, i, j);
        my_putchar('\n');
        return (0);
    }
    return (84);
}

int size3(char *buff, int i, int j)
{
    if (buff[0] == 'A' && buff[i - 1] == 'A') {
        print(3, i, j);
        my_putchar('\n');
        return (0);
    }
    if (buff[0] == 'A' && buff[i - 1] == 'C') {
        for (int k = i; buff[k] != '\0'; k++) {
            if (size3part2(buff, i, j, k) == 0)
                return (0);
        }
    }
    return (84);
}

int size2(char *buff, int i, int j)
{
    if (my_strlen(buff) > 4095)
        return (84);
    if (buff[0] == 'o') {
        print(1, i, j);
        my_putchar('\n');
        return (0);
    }
    if (buff[0] == '/') {
        print(2, i, j);
        my_putchar('\n');
        return (0);
    }
    return (size3(buff, i, j));
}