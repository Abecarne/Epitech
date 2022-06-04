/*
** EPITECH PROJECT, 2022
** rush02
** File description:
** test the functions of float
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "include/new.h"
#include "include/object.h"
#include "include/float.h"

static void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//--------------------Operators--------------------

Test(addition, test_float, .init=redirect_stdout)
{
    Object  *v1 = new(Float, -1.0);
    Object  *v2 = new(Float, 100.0);
    Object *v3 = addition(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    delete(v3);
    delete(v1);
    delete(v2);
    free(str);
    cr_assert_stdout_eq_str("<Float (99.000000)>", "");
}

Test(subtraction, test_float, .init=redirect_stdout)
{
    Object  *v1 = new(Float, -1.0);
    Object  *v2 = new(Float, 100.0);
    Object *v3 = subtraction(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Float (-101.000000)>", "");
}

Test(multiplication, test_float, .init=redirect_stdout)
{
    Object  *v1 = new(Float, 5.0);
    Object  *v2 = new(Float, 2.0);
    Object *v3 = multiplication(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Float (10.000000)>", "");
}

Test(divide, test_float, .init=redirect_stdout)
{
    Object  *v1 = new(Float, 5.0);
    Object  *v2 = new(Float, 2.0);
    Object *v3 = division(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Float (2.500000)>", "");
}

Test(divide_zero, test_float, .init=redirect_stdout, .signal = SIGABRT)
{
    Object  *v1 = new(Float, -1804289383.0);
    Object  *v2 = new(Float, 0.0);
    Object *v3 = division(v1, v2);
    char *str = str(v3);

    free(str);
    delete(v3);
    cr_assert_stderr_eq_str("float.c: 71: Cannot divide by 0", "");
}

//----------------Comparaisons-----------------------

Test(equal, test_float, .init=redirect_stdout)
{
    Object  *v1 = new(Float, -1804289383.0);
    Object  *v2 = new(Float, 1681692777.0);
    bool res = eq(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, false);
}

Test(greater, test_float, .init=redirect_stdout)
{
    Object  *v1 = new(Float, -1804289383.0);
    Object  *v2 = new(Float, 1681692777.0);
    bool res = gt(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, false);
}

Test(lower, test_float, .init=redirect_stdout)
{
    Object  *v1 = new(Float, -1804289383.0);
    Object  *v2 = new(Float, 1681692777.0);
    bool res = lt(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, true);
}
