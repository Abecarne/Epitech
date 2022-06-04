/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday05-simon.auduberteau
** File description:
** my_compute_power_it
*/

int  my_compute_power_rec(int nb , int p)
{
    int res = nb;

    if (p == 0)
        return (1);
    if (p < 0 || nb == 0)
        return (0);
    if (p > 1)
        res *= my_compute_power_rec(nb, p -1);
    if (p % 2 == 0 && res < 0)
        return (0);
    return (res);
}