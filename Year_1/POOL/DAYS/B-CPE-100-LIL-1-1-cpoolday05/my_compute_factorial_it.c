/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int resultat = nb;

    if (nb == 0) {
        return (1);
    } else if (nb < 0 || nb > 12) {
        return (0);
    } else {
        while (nb > 1) {
            resultat *= (nb - 1);
            nb--;
        }
    }
    return (resultat);
}