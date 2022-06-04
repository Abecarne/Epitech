/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** copy
*/

#include "string.h"

size_t copy(const string_t *this , char *s, size_t n, size_t pos)
{
    s = malloc(sizeof(char) * strlen(this->str));
    return (strlen(strncpy(s, this->str + pos, n)));
}