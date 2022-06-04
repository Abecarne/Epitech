/*
** EPITECH PROJECT, 2022
** B-PDG-300-LIL-3-1-PDGRUSH2-simon.auduberteau
** File description:
** new
*/

#include "player.h"
#include "new.h"

Object *new(const Class *class, ...)
{
    va_list args;
    Object *ret;

    va_start(args, class);
    ret = va_new(class, &args);
    va_end(args);
    return (ret);
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *ret;

    ret = malloc(class->__size__);
    if (ret == NULL)
        return (NULL);
    memcpy(ret, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(ret, ap);
    return (ret);
}

void delete(Object *ptr)
{
    if (((Class *)ptr)->__dtor__ != NULL)
        ((Class *)ptr)->__dtor__(ptr);
    free(ptr);
}
