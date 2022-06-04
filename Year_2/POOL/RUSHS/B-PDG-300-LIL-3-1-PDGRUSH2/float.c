/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float nb;
} FloatClass;

static void float_ctor(FloatClass *this, va_list *args)
{
    this->nb = va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    (void)this;
}

static char *float_str(FloatClass *this)
{
    char str[100];

    sprintf(str, "<%s (%f)>", this->base.__name__, this->nb);
    return (strdup(str));
}

static Object *add(FloatClass *first, FloatClass *second)
{
    float nb_added = first->nb + second->nb;
    Object *ret = new(Float, nb_added);

    return (ret);
}

static Object *sub(FloatClass *first, FloatClass *second)
{
    float nb_subbed = '\0';
    Object *ret = NULL;

    nb_subbed = first->nb - second->nb;
    ret = new(Float, nb_subbed);

    return (ret);
}

static Object *mul(FloatClass *first, FloatClass *second)
{
    float nb_mul = first->nb * second->nb;
    Object *ret = new(Float, nb_mul);

    return (ret);
}

static Object *divide(FloatClass *first, FloatClass *second)
{
    float ch_div = '\0';
    Object *ret = NULL;

    if (second->nb == 0)
        raise("Cannot divide by 0");
    ch_div = first->nb / second->nb;
    ret = new(Float, ch_div);

    return (ret);
}

static bool equal(FloatClass *first, FloatClass *second)
{
    bool ret = first->nb == second->nb;

    return (ret);
}

static bool greater(FloatClass *first, FloatClass *second)
{
    bool ret = first->nb > second->nb;

    return (ret);
}

static bool lower(FloatClass *first, FloatClass *second)
{
    bool ret = first->nb < second->nb;

    return (ret);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = (to_string_t)&float_str,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = (binary_operator_t)&mul,
        .__div__ = (binary_operator_t)&divide,
        .__eq__ = (binary_comparator_t)&equal,
        .__gt__ = (binary_comparator_t)&greater,
        .__lt__ = (binary_comparator_t)&lower
    },
    .nb = 0,
};

const Class *Float = (const Class *)&_description;
