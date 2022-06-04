/*
** EPITECH PROJECT, 2022
** delivery [WSL: Ubuntu-20.04]
** File description:
** append
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    this->str = strcat(this->str, ap->str);
}

void append_c(string_t *this, const char *ap)
{
    this->str = strcat(this->str, ap);
}
