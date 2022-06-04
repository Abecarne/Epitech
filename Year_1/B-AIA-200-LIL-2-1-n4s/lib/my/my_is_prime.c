/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday05-simon.auduberteau
** File description:
** my_is_prime
*/

int  my_is_prime(int nb)
{
    if (nb == 0 || nb == 1 || nb < 0)
        return (0);
    for (int i = 2; i < nb; i++) {
        if (nb % i == 0)
            return (0);
    }
    return (1);
}