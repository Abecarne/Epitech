/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_compute_power_it
*/

int  my_compute_power_it(int nb , int p)
{
    int resultat_final = 1;

    if (p < 0 || nb < -214748368 || nb > 2147483647) {
        return (0);
    }
    while (p >= 1) {
        resultat_final *= nb;
        p--;
    }
    return (resultat_final);
}

