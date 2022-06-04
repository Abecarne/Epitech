/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** compute square
*/

int my_compute_square_root(int nb)
{
    int power = 0;

    for (int i = 0; i * i < nb && i * i > 0; i += 3)
        power += 3;
    while (power * power != nb && power != 0)
        power--;
    return (power);
}
