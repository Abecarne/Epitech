/*
** EPITECH PROJECT, 2020
** delivery [WSL: fedora]
** File description:
** my_put_maj_s
*/
#include "../../include/my.h"

void my_put_maj_s(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 8) {
            my_putstr("\\00");
            my_change_base(str[i], 8);
        } else if (str[i] >= 8 && str[i] < 32) {
            my_putstr("\\0");
            my_change_base(str[i], 8);
        } else {
            my_putchar(str[i]);
        }
    }
}