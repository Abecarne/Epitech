/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** compute power rec
*/

int my_compute_power_rec(int nb, int p)
{
    int value = nb;

    if (p == 0)
        return (1);
    if (p > 0)
        value *= my_compute_power_rec(nb, p - 1);
    if (value / nb != my_compute_power_rec(nb, p - 1))
        return (0);
    return (value);
}
