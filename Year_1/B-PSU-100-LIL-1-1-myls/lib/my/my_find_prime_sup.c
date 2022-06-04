/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_find_prime_sup
*/

int  my_find_prime_sup(int nb)
{

    if (nb <= 2) {
        return (2);
    }
    if (nb >= 2147483647) {
        return (0);
    }
    while (my_is_prime(nb) == 0) {
        nb++;
        if (my_is_prime(nb) == 1) {
            return (nb);
        }
    }
}

