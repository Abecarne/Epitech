/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_put_nbr
*/

int  my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('2');
        nb = -147483648;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 9) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + 48);
    return (0);
}