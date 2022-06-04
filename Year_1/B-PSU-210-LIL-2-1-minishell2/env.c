/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** env
*/

#include "include/minishell.h"

void exec_env(st_minishell *st)
{
    for (int i = 0; st->env[i] != NULL; i++)
        my_printf("%s\n", st->env[i]);
}

void exec_setenv(st_minishell *st)
{
    char **cp = copy_2d_array(st->env);

    if (error_setenv(st) == 0)
        switch (nb_lines_tab(st->arg[st->cm])) {
            case 1:
                exec_env(st);
                break;
            case 2:
                st->env = copy_2d_array(create_var(st, cp, st->arg[st->cm][1]));
                break;
            case 3:
                st->env = copy_2d_array(replace_var(st, cp));
                break;
            default:
                break;
        }
}

void exec_unsetenv(st_minishell *st)
{
    char **copie = copy_2d_array(st->env);

    if (error_unsetenv(st) == 0) {
        st->env = copy_2d_array(delete_var(st, copie));
    }
}
