/*
** EPITECH PROJECT, 2022
** rush02
** File description:
** test the functions of int
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include "include/new.h"
#include "include/object.h"
#include "include/int.h"

static void redirect_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

//--------------------Operators--------------------

Test(addition, test_int, .init=redirect_stdout)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 1681692777);
    Object *v3 = addition(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    delete(v3);
    delete(v1);
    delete(v2);
    free(str);
    cr_assert_stdout_eq_str("<Int (-122596606)>", "");
}

Test(subtraction, test_int, .init=redirect_stdout)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 1681692777);
    Object *v3 = subtraction(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Int (808985136)>", "");
}

Test(multiplication, test_int, .init=redirect_stdout)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 1681692777);
    Object *v3 = multiplication(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Int (-1299750719)>", "");
}

Test(divide, test_int, .init=redirect_stdout)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 1681692777);
    Object *v3 = division(v1, v2);
    char *str = str(v3);

    write(1, str, strlen(str));
    free(str);
    delete(v1);
    delete(v2);
    delete(v3);
    cr_assert_stdout_eq_str("<Int (-1)>", "");
}

Test(divide_zero, test_int, .init=redirect_stdout, .signal = SIGABRT)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 0);
    Object *v3 = division(v1, v2);
    char *str = str(v3);

    free(str);
    delete(v3);
    cr_assert_stderr_eq_str("int.c: 74: Cannot divide by 0", "");
}

//----------------Comparaisons-----------------------

Test(equal, test_int, .init=redirect_stdout)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 1681692777);
    bool res = eq(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, false);
}

Test(greater, test_int, .init=redirect_stdout)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 1681692777);
    bool res = gt(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, false);
}

Test(lower, test_int, .init=redirect_stdout)
{
    Object  *v1 = new(Int, -1804289383);
    Object  *v2 = new(Int, 1681692777);
    bool res = lt(v1, v2);

    delete(v1);
    delete(v2);
    cr_assert_eq(res, true);
}
