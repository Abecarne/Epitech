/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday04-simon.auduberteau
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c = 0;

    c = *a;
    *a = *b;
    *b = c;
}