/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Task 01
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *b;
    *b = *a;
    *a = c;
}
