/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int division = 1;

    if (nb < 0) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar(50);
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < 10)
        my_putchar(nb + 48);
    if (nb >= 10) {
        my_put_nbr(nb / 10);
        division = (nb % 10);
        my_putchar(division + 48);
    }
    return (0);
}