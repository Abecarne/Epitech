/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** compare
*/

#include "string.h"

int compare_s(const string_t *this , const string_t *str)
{
    if (this->str != NULL && str->str != NULL)
        return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this , const char *str)
{
    return (strcmp(this->str, str));
}