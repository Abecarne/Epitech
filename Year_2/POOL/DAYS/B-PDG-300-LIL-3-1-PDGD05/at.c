/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** at
*/

#include "string.h"

char my_at(const string_t *this, size_t pos)
{
    if (pos >= 0 && pos <= (strlen(this->str) - 1))
        return (this->str[pos]);
    return (-1);
}
