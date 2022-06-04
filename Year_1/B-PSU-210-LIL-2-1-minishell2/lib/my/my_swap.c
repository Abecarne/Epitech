/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_swap
*/

int my_swap(int *a, int *b)
{
    int copie = *a;

    *a = *b;
    *b = copie;
}
