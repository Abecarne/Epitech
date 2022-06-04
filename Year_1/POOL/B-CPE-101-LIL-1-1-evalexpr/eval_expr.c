/*
** EPITECH PROJECT, 2020
** tempo
** File description:
** eval_expr
*/

#include "my.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *replace_parent(char *dest);

char *replace_cpy(char *cpy, char *dest, char *str);

int launch(char *str);

int operate(char *str);

void free_var(char *cpy_str, char *dest)
{
    free(cpy_str);
    free(dest);
}

int check_parent(char *str)
{
    int cmp_ov = 0;
    int cmp_f = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(')
            cmp_ov++;
        if (str[i] == ')')
            cmp_f++;
    }
    if (cmp_f == cmp_ov)
        return (0);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(')
            return (1);
    return (0);
}

int check_parent_final_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '(')
            return (1);
    return (0);
}

char *pick_calc(char *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    int index_dest = 0;
    int cpt = 0;
    int cmp_par = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            cpt++;
            cmp_par++;
            for (; str[i] != ')'; i++, index_dest++)
                dest[index_dest] = str[i];
            if (str[i] == ')') {
                dest[index_dest] = str[i];
                dest[index_dest + 1] = '\0';
                return (dest);
            }
        }
    }
    return (dest);
}

int eval_expr(char *str)
{
    return (operate(str));
}