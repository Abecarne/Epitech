/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** print
*/

#include "print.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

void print_upper(const char *str)
{
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z' && str[i] != ' ')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void print_42(const char *str)
{
    (void)str;
    write(1, "42\n", 3);
}

void do_action(action_t action, const char *str)
{
    void (*fct[4])(const char *) = {&print_normal,
                                    &print_reverse,
                                    &print_upper,
                                    &print_42};
    fct[action](str);
}
