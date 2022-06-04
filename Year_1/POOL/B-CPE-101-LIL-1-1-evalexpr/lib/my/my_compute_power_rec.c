/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_compute_power_rec
*/

int  my_compute_power_rec(int nb , int p)
{
    long res = nb;

    if (p == 1) {
        return (res);
    } else  if (p > 1) {
        res = res * my_compute_power_rec(nb, p - 1);
        return (res);
    }
    if (res < -2147483648 || res > 2147483647) {
        return (0);
    }
}