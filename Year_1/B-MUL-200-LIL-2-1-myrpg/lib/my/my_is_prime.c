/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** prime nbr
*/

int my_is_prime(int nb)
{
    if (nb == 2)
        return (1);
    if (nb == 0 || nb == 1)
        return (0);
    if (nb % 2 == 0)
        return (0);
    else
        return (1);
}
