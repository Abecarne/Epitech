/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_compute_square_root
*/

int  my_compute_square_root(int nb)
{
    int final = 0;

    if ((nb <= 0) || (nb >= 2147483647)
    || ((nb / 1) != nb) || ((final / 1) != final)){
        return (0);
    }
    for (int i = 0; i <= (nb / 2); i++) {
        if (i * i > nb) {
            return (0);
        }
        if ((i * i) == nb) {
            return (i);
        }
    }
}
