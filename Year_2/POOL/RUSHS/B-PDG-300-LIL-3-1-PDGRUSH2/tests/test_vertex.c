/*
** EPITECH PROJECT, 2022
** rush02
** File description:
** test vertex
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "include/new.h"
#include "include/vertex.h"

static void redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(vertex, vertex_output, .init=redirect_stdout)
{
    Object *vertex = new(Vertex, 42, -42, 100);
    char *str = str(vertex);

    write(1, str, strlen(str));
    delete(vertex);
    free(str);
    cr_assert_stdout_eq_str("<Vertex (42, -42, 100)>", "");
}

Test(add, add_vertex, .init=redirect_stdout)
{
    Object *vertex = new(Vertex, 42, -42, 0);
    Object *vertex2 = new(Vertex, -42, 42, 0);
    Object *vertex_add = addition(vertex, vertex2);
    char *str = str(vertex_add);

    write(1, str, strlen(str));
    delete(vertex);
    delete(vertex2);
    delete(vertex_add);
    free(str);
    cr_assert_stdout_eq_str("<Vertex (0, 0, 0)>", "");
}

Test(sub, sub_vertex, .init=redirect_stdout)
{
    Object *vertex = new(Vertex, 42, -42, 100);
    Object *vertex2 = new(Vertex, 42, -42, 100);
    Object *vertex_sub = subtraction(vertex, vertex2);
    char *str = str(vertex_sub);

    write(1, str, strlen(str));
    delete(vertex);
    delete(vertex2);
    delete(vertex_sub);
    free(str);
    cr_assert_stdout_eq_str("<Vertex (0, 0, 0)>", "");
}
