/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_put_nbr
*/

void my_putchar(char c);

int  my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        my_put_nbr(147483648);
    }
    if (nb < 0)
        my_putchar('-');
        nb = nb * -1;
    if (nb >= 9)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
    return (0);
}