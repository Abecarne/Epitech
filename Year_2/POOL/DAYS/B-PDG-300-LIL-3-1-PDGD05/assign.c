/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** assign
*/

#include "string.h"

void assign_s(string_t *this, const string_t *str)
{
    if (this->str != NULL && str->str != NULL) {
        free(this->str);
        this->str = strdup(str->str);
    }
}

void assign_c(string_t *this, const char *s)
{
    if (this->str != NULL) {
        free(this->str);
        this->str = strdup(s);
    }
}
