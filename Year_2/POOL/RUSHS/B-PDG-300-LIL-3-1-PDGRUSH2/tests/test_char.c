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
#include <stdbool.h>
#include "include/new.h"
#include "include/object.h"
#include "include/char.h"

static void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//--------------------Operators--------------------

Test(addition, test_char, .init=redirect_stdout)
{
    Object  *v1 = new(Char, 'A');
    Object  *v2 = new(Char, ' ');
    Object *v3 = addition(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    delete(v3);
    delete(v1);
    delete(v2);
    free(str);
    cr_assert_stdout_eq_str("<Char (a)>", "");
}

Test(subtraction, test_char, .init=redirect_stdout)
{
    Object  *v1 = new(Char, 'a');
    Object  *v2 = new(Char, ' ');
    Object *v3 = subtraction(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Char (A)>", "");
}

Test(multiplication, test_char, .init=redirect_stdout)
{
    Object  *v1 = new(Char, '#');
    Object  *v2 = new(Char, 2);
    Object *v3 = multiplication(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Char (F)>", "");
}

Test(divide, test_char, .init=redirect_stdout)
{
    Object  *v1 = new(Char, 'F');
    Object  *v2 = new(Char, 2);
    Object *v3 = division(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Char (#)>", "");
}

Test(divide_zero, test_char, .init=redirect_stdout, .signal = SIGABRT)
{
    Object  *v1 = new(Char, 'z');
    Object  *v2 = new(Char, 0);
    Object *v3 = division(v1, v2);
    char *str = str(v3);

    free(str);
    delete(v3);
    cr_assert_stderr_eq_str("char.c: 70: Cannot divide by 0", "");
}

//----------------Comparaisons-----------------------

Test(equal, test_char, .init=redirect_stdout)
{
    Object  *v1 = new(Char, '#');
    Object  *v2 = new(Char, '*');
    bool res = eq(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, false);
}

Test(greater, test_char, .init=redirect_stdout)
{
    Object  *v1 = new(Char, '#');
    Object  *v2 = new(Char, '*');
    bool res = gt(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, false);
}

Test(lower, test_char, .init=redirect_stdout)
{
    Object  *v1 = new(Char, '#');
    Object  *v2 = new(Char, '*');
    bool res = lt(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, true);
}
