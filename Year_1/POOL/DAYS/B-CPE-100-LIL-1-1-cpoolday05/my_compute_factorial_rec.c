/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_compute_factorial_rec
*/

int my_compute_factorial_rec(int nb)
{
    int resultat = nb;

    if (nb == 0) {
        return (1);
    } else if (nb < 0 || nb > 12) {
        return (0);
    } else {
        if (nb >= 1) {
            resultat *= my_compute_factorial_rec(nb - 1);            
        }
    }
    return (resultat);
}
