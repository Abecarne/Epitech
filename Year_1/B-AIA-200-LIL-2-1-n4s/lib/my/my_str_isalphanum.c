/*
** EPITECH PROJECT, 2021
** B-PSU-210-LIL-2-1-minishell2-simon.auduberteau
** File description:
** my_str_isalphanum
*/

int my_str_isalphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= '0' && str[i] <= '9') ||
            (str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') || str[i] == '_');
        else
            return -1;
    }
    return 0;
}