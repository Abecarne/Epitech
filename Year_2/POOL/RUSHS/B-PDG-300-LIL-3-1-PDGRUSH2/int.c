/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class base;
    int nb;
} IntClass;

static void int_ctor(IntClass *this, va_list *args)
{
    this->nb = va_arg(*args, int);
}

static void int_dtor(IntClass *this)
{
    (void)this;
}

static char *int_str(IntClass *this)
{
    char *str;
    int len = strlen(this->base.__name__) + 7;

    if (this->nb < 0)
        len++;
    for (int i = abs(this->nb); i >= 10; i /= 10)
        len++;
    str = malloc(sizeof(char) * len);
    if (str == NULL)
        raise("Cannot alloc memory");
    sprintf(str, "<%s (%i)>", this->base.__name__, this->nb);
    return (str);
}

static Object *add(IntClass *first, IntClass *second)
{
    int nb_added = first->nb + second->nb;
    Object *ret = new(Int, nb_added);

    return (ret);
}

static Object *sub(IntClass *first, IntClass *second)
{
    int nb_subbed = first->nb - second->nb;
    Object *ret = new(Int, nb_subbed);

    return (ret);
}

static Object *mul(IntClass *first, IntClass *second)
{
    int nb_mul = first->nb * second->nb;
    Object *ret = new(Int, nb_mul);

    return (ret);
}

static Object *divide(IntClass *first, IntClass *second)
{
    int ch_div = '\0';
    Object *ret = NULL;

    if (second->nb == 0)
        raise("Cannot divide by 0");
    ch_div = first->nb / second->nb;
    ret = new(Int, ch_div);

    return (ret);
}

static bool equal(IntClass *first, IntClass *second)
{
    bool ret = first->nb == second->nb;

    return (ret);
}

static bool greater(IntClass *first, IntClass *second)
{
    bool ret = first->nb > second->nb;

    return (ret);
}

static bool lower(IntClass *first, IntClass *second)
{
    bool ret = first->nb < second->nb;

    return (ret);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&int_ctor,
        .__dtor__ = (dtor_t)&int_dtor,
        .__str__ = (to_string_t)&int_str,
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

const Class *Int = (const Class *)&_description;
