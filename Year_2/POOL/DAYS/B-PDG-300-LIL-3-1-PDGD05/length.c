/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** length
*/

#include "string.h"

int length(const string_t *this)
{
    if (this->str == NULL)
        return (-1);
    return (strlen(this->str));
}
