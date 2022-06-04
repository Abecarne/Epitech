/*
** EPITECH PROJECT, 2021
** delivery [WSL: fedora]
** File description:
** main
*/

#include "include/minishell.h"

int reading(st_minishell *st)
{
    int str = 0;
    size_t cp = 0;
    char *tmp = NULL;

    str = getline(&tmp, &cp, stdin);
    if (str == -1) {
        my_printf("exit\n");
        st->return_value = 0;
        return (1);
    }
    st->input = my_strdup(tmp);
    return (0);
}

void executing_many_cmd(st_minishell *st)
{
    for (int i = 0; st->arg[i] != NULL; i++) {
        if (breaker(st) == 1) {
            st->status = 1;
            break;
        }
        if (is_symbol(st) != 1)
            if (check_builtin(st) == 0)
            execute(st);
        st->cm++;
    }
}

int main_loop(st_minishell *st)
{
    while (st->status != 1) {
        getcwd(st->current, 512);
        my_printf("%s$ ", st->current);
        st->cm = 0;
        if (reading(st) == 1)
            break;
        if (is_empty_line(st->input) == 0) {
            rm_backslash(st);
            st->input = clean_input(st->input);
            st->input = check_valid_input(st->input);
            st->arg = triple_parse(st);
            executing_many_cmd(st);
        }
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    st_minishell *st = malloc(sizeof(st_minishell));

    if (!st)
        return (84);
    if (error_handler(ac, av) == 84)
        return (84);
    init_struct(st, env);
    st->current = malloc(sizeof(char) * 512);
    if (!st->current)
        return (84);
    getcwd(st->current, 512);
    return (main_loop(st) == 84 ? 84 : st->return_value);
}
