/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** regex
*/

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int regex_match(char *str, char *regex, int n)
{
    regex_t reg;
    int res;
    int flags = REG_EXTENDED | REG_NOSUB | REG_NEWLINE;

    if (regcomp(&reg, regex, flags) != 0)
        return (84);
    res = regexec(&reg, str, 0, NULL, 0);
    regfree(&reg);
    return (res);
}
