/*
** EPITECH PROJECT, 2022
** rush02
** File description:
** test point
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "include/new.h"
#include "include/point.h"
#include <unistd.h>

static void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(point, point_output, .init=redirect_stdout)
{
    Object *point = new(Point, 42, -42);
    char *str = str(point);

    write(1, str, strlen(str));
    delete(point);
    free(str);
    cr_assert_stdout_eq_str("<Point (42, -42)>", "");
}

Test(add, add_point, .init=redirect_stdout)
{
    Object *point = new(Point, 42, -42);
    Object *point2 = new(Point, -42, 42);
    Object *point_add = addition(point, point2);
    char *str = str(point_add);

    write(1, str, strlen(str));
    delete(point);
    delete(point2);
    delete(point_add);
    free(str);
    cr_assert_stdout_eq_str("<Point (0, 0)>", "");
}

Test(sub, sub_point, .init=redirect_stdout)
{
    Object *point = new(Point, 42, -42);
    Object *point2 = new(Point, 42, -42);
    Object *point_sub = subtraction(point, point2);
    char *str = str(point_sub);

    write(1, str, strlen(str));
    delete(point);
    delete(point2);
    delete(point_sub);
    free(str);
    cr_assert_stdout_eq_str("<Point (0, 0)>", "");
}
