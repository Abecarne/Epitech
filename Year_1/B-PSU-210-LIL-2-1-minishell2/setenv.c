/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** setenv
*/

#include "include/minishell.h"

char *clean_var_env(char *str)
{
    int i = 0;
    char *res = malloc(sizeof(char) * 4096);

    for (i = 0; str[i] != '\0'; i++) {
        res[i] = str[i];
        if (str[i] == '=')
            break;
    }
    return (res);
}

char *change_var(char *dest, char *src)
{
    int i = 0;
    char *res = NULL;
    char *until_equal = malloc(sizeof(char) * my_strlen(dest) + 1);

    for (i = 0; dest[i] != '='; i++) {
        until_equal[i] = dest[i];
    }
    until_equal[i] = dest[i];
    res = my_strdup(my_strcat(until_equal, src));
    return (res);
}

int existing_var(const char *check, const char *s2)
{
    int i = 0;

    for (; check[i] != '\0'; i++) {
        if (check[i] == '=')
            break;
    }
    if (i != my_strlen(s2))
        return (1);
    return (my_strncmp(check, s2, i));
}

char **replace_var(st_minishell *st, char **copie)
{
    int i = 0;
    int exist = 0;
    char **more = copy_2d_array(copie);

    for (; copie[i] != NULL; i++) {
        if (existing_var(copie[i], st->arg[st->cm][1]) == 0) {
            more[i] = change_var(more[i], st->arg[st->cm][2]);
            exist = 1;
            break;
        }
    }
    if (exist == 0) {
        more = copy_2d_array(create_var(st, copie, st->arg[st->cm][1]));
        more[nb_lines_tab(more) - 1] = change_var(more[i], st->arg[st->cm][2]);
    }
    return (more);
}

char **create_var(st_minishell *st, char **cp_env, char *src)
{
    int i = 0;
    char **more = copy_2d_array(cp_env);
    int line = nb_lines_tab(cp_env);
    int exist = 0;

    for (; cp_env[i] != NULL; i++) {
        if (existing_var(cp_env[i], st->arg[st->cm][1]) == 0) {
            more[i] = clean_var_env(more[i]);
            exist = 1;
            break;
        }
    }
    if (exist == 0) {
        more = add_line_array(cp_env);
        more[line] = my_strdup(my_strcat(src, "="));
        more[line][my_strlen(more[line])] = '\0';
    }
    return (more);
}