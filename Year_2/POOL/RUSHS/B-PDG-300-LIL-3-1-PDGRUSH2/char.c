/*
** EPITECH PROJECT, 2022
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char ch;
} CharClass;

static void char_ctor(CharClass *this, va_list *args)
{
    this->ch = va_arg(*args, int);
}

static void char_dtor(CharClass *this)
{
    (void)this;
}

static char *char_str(CharClass *this)
{
    char *str;
    int len = strlen(this->base.__name__) + 7;

    str = malloc(sizeof(char) * len);
    if (str == NULL)
        raise("Cannot alloc memory");
    sprintf(str, "<%s (%c)>", this->base.__name__, this->ch);
    return (str);
}

static Object *add(CharClass *first, CharClass *second)
{
    char ch_added = first->ch + second->ch;
    Object *ret = new(Char, ch_added);

    return (ret);
}

static Object *sub(CharClass *first, CharClass *second)
{
    char ch_subbed = first->ch - second->ch;
    Object *ret = new(Char, ch_subbed);

    return (ret);
}

static Object *mul(CharClass *first, CharClass *second)
{
    char ch_mul = first->ch * second->ch;
    Object *ret = new(Char, ch_mul);

    return (ret);
}

static Object *divide(CharClass *first, CharClass *second)
{
    char ch_div = '\0';
    Object *ret = NULL;

    if (second->ch == 0)
        raise("Cannot divide by 0");
    ch_div = first->ch / second->ch;
    ret = new(Char, ch_div);

    return (ret);
}

static bool equal(CharClass *first, CharClass *second)
{
    bool ret = first->ch == second->ch;

    return (ret);
}

static bool greater(CharClass *first, CharClass *second)
{
    bool ret = first->ch > second->ch;

    return (ret);
}

static bool lower(CharClass *first, CharClass *second)
{
    bool ret = first->ch < second->ch;

    return (ret);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&char_ctor,
        .__dtor__ = (dtor_t)&char_dtor,
        .__str__ = (to_string_t)&char_str,
        .__add__ = (binary_operator_t)&add,
        .__sub__ = (binary_operator_t)&sub,
        .__mul__ = (binary_operator_t)&mul,
        .__div__ = (binary_operator_t)&divide,
        .__eq__ = (binary_comparator_t)&equal,
        .__gt__ = (binary_comparator_t)&greater,
        .__lt__ = (binary_comparator_t)&lower
    },
    .ch = 0,
};

const Class *Char = (const Class *)&_description;
