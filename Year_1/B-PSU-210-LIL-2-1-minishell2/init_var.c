/*
** EPITECH PROJECT, 2021
** delivery [WSL: Ubuntu-20.04]
** File description:
** init_var
*/

#include "include/minishell.h"

int init_struct(st_minishell *st, char **env)
{
    st->return_value = 0;
    st->arg = malloc(sizeof(char **) * 20);
    if (!st->arg)
        exit(84);
    st->input = NULL;
    st->builtin = 0;
    st->previous = NULL;
    st->cm = 0;
    st->status = 0;
    st->env = copy_2d_array(env);
    return (0);
}

void rm_backslash(st_minishell *st)
{
    for (int i = 0; st->input[i] != '\0'; i++)
        if (st->input[i] == '\n') {
            st->input[i] = '\0';
            break;
        }
}

int with_pipe(char *str)
{
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '|')
            return (0);
    my_printf("Invalid null command.\n");
    return (1);
}

int with_virgule(char *str)
{
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] != ' ' && str[i] != '\t' && str[i] != ';')
            return (0);
    return (1);
}

int with_no_pipe(char *str)
{
    for (int i = 0; str[i] != '\n'; i++)
        if (str[i] != ' ' && str[i] != '\t')
            return (0);
    return (1);
}

int is_empty_line(char *str)
{
    if (char_in_str(str, '|') == 0)
        return (with_pipe(str));
    else if (char_in_str(str, ';') == 0)
        return (with_virgule(str));
    else
        return (with_no_pipe(str));
}
