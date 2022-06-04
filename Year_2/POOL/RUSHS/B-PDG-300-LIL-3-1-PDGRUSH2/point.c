/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
} PointClass;

static void point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void point_dtor(PointClass *this)
{
    (void)this;
}

static char *point_str(PointClass *this)
{
    char *str;
    int len = strlen(this->base.__name__) + 11;

    for (int i = abs(this->x); i >= 10; i /= 10)
        len++;
    for (int i = abs(this->y); i >= 10; i /= 10)
        len++;
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        raise("Cannot alloc memory");
    sprintf(str, "<%s (%i, %i)>", this->base.__name__, this->x, this->y);
    return (str);
}

static Object *add(PointClass *first, PointClass *second)
{
    int x_added = first->x + second->x;
    int y_added = first->y + second->y;
    Object *ret = new(Point, x_added, y_added);

    return (ret);
}

static Object *sub(PointClass *first, PointClass *second)
{
    int x_subbed = first->x - second->x;
    int y_subbed = first->y - second->y;
    Object *ret = new(Point, x_subbed, y_subbed);

    return (ret);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&point_ctor,
        .__dtor__ = (dtor_t)&point_dtor,
        .__str__ = (to_string_t)&point_str,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
