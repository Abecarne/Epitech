/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "vertex.h"
#include "new.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void vertex_dtor(VertexClass *this)
{
    (void)this;
}

static char *vertex_str(VertexClass *this)
{
    char *str;
    int len = strlen(this->base.__name__) + 14;

    for (int i = abs(this->x); i >= 10; i /= 10)
        len++;
    for (int i = abs(this->y); i >= 10; i /= 10)
        len++;
    for (int i = abs(this->z); i >= 10; i /= 10)
        len++;
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        raise("Cannot alloc memory");
    sprintf(str, "<%s (%i, %i, %i)>", this->base.__name__,
        this->x, this->y, this->z);
    return (str);
}

static Object *add(VertexClass *first, VertexClass *second)
{
    int x_added = first->x + second->x;
    int y_added = first->y + second->y;
    int z_added = first->z + second->z;
    Object *ret = new(Vertex, x_added, y_added, z_added);

    return (ret);
}

static Object *sub(VertexClass *first, VertexClass *second)
{
    int x_subbed = first->x - second->x;
    int y_subbed = first->y - second->y;
    int z_subbed = first->z - second->z;
    Object *ret = new(Vertex, x_subbed, y_subbed, z_subbed);

    return (ret);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&vertex_ctor,
        .__dtor__ = (dtor_t)&vertex_dtor,
        .__str__ = (to_string_t)&vertex_str,
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

const Class *Vertex = (const Class *)&_description;
