/*
** EPITECH PROJECT, 2022
** delivery
** File description:
** clear_list
*/

#include "string.h"

void clear(string_t *this)
{
    this->str = strcpy(this->str, "");
}
