/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Display a number
*/

char my_putchar(char c);

int my_put_nbr(int nb)
{
    int a = 0;

    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    if (nb >= 0 && nb <= 9)
        my_putchar(nb + 48);
    if (nb > 9) {
        a = nb % 10;
        nb = (nb - a) / 10;
        my_put_nbr(nb);
        my_putchar(a + 48);
    }
}
