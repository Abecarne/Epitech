/*
** EPITECH PROJECT, 2022
** rush02
** File description:
** test the functions of char
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <signal.h>
#include "include/new.h"
#include "include/object.h"
#include "include/char.h"
#include "include/array.h"

static void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(array, test_basic_array, .init=redirect_stdout)
{
    Object  *array = new(Array, 10, Char, 's');
    Object  *it = begin(array);
    Object  *it_end = end(array);
    char *str = NULL;

    setitem(array, 5, 'h');
    setitem(array, 6, 'i');
    setval(it, 88);
    while (lt(it, it_end)) {
        str = str(getval(it));
        write(1, str, strlen(str));
        free(str);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
    cr_assert_stdout_eq_str("<Char (X)><Char (s)><Char (s)><Char (s)><Char (s)><Char (h)><Char (i)><Char (s)><Char (s)><Char (s)>", "");
}

Test(array, test_len, .init=redirect_stdout)
{
    Object  *array = new(Array, 10, Char, 's');
    size_t len = len(array);

    delete(array);
    cr_assert_eq(len, 10);
}

Test(getitem, test_getItem, .init=redirect_stdout)
{
    Object  *array = new(Array, 10, Char, 's');
    char *str = str(getitem(array, 0));

    write(1, str, strlen(str));
    delete(array);
    free(str);
    cr_assert_stdout_eq_str("<Char (s)>", "");
}

//----------------Errors-----------------------------
Test(getval, test_array_error, .init=redirect_stdout, .signal = SIGABRT)
{
    Object  *array = new(Array, 10, Char, 's');
    Object  *it_end = end(array);

    incr(it_end);
    getval(it_end);

    delete(it_end);
    delete(array);
    cr_assert_stderr_eq_str("array.c: 57: Out of range", "");
}

Test(getitem_out_of_range, test_array_error, .init=redirect_stdout, .signal = SIGABRT)
{
    Object  *array = new(Array, 10, Char, 's');

    getitem(array, 11);

    delete(array);
    cr_assert_stderr_eq_str("array.c: 154: Out of range", "");
}

Test(setitem_out_of_range, test_basic_array, .init=redirect_stdout, .signal = SIGABRT)
{
    Object  *array = new(Array, 10, Char, 's');

    setitem(array, 11, 'h');
    delete(array);
    cr_assert_stderr_eq_str("array.c: 168: Out of range", "");
}

//----------------Comparaisons-----------------------

Test(equal, test_array_comp, .init=redirect_stdout)
{
    Object  *array = new(Array, 10, Char, 's');
    Object  *it = begin(array);
    Object  *it_end = end(array);
    bool res = eq(it, it_end);

    delete(it);
    delete(it_end);
    delete(array);
    cr_assert_eq(res, false);
}

Test(greater, test_array_comp, .init=redirect_stdout)
{
    Object  *array = new(Array, 10, Char, 's');
    Object  *it = begin(array);
    Object  *it_end = end(array);
    bool res = gt(it, it_end);

    delete(it);
    delete(it_end);
    delete(array);
    cr_assert_eq(res, false);
}

Test(lower, test_array_comp, .init=redirect_stdout)
{
    Object  *array = new(Array, 10, Char, 's');
    Object  *it = begin(array);
    Object  *it_end = end(array);
    bool res = lt(it, it_end);

    delete(it);
    delete(it_end);
    delete(array);
    cr_assert_eq(res, true);
}
