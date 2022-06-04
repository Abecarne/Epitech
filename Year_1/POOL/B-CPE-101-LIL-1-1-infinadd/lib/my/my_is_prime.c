/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_is_prime
*/

int  my_is_prime(int nb)
{
    int i = 2;

    if ((nb <= 1) || (nb >= 2147483648)) {
        return (0);
    }
    for (i; i < nb - 1; i++) {
        if ((nb % i) == 0) {
            return (0);
        }
    }
    return (1);
}