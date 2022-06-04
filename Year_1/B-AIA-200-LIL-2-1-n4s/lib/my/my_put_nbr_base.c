/*
** EPITECH PROJECT, 2019
** my_put_nbr_base
** File description:
** my_put_nbr_base
*/
int	my_put_nbr_base(int nb, char *base)
{
    int	res;
    int	rest;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    res = nb / my_strlen(base);
    rest = nb % my_strlen(base);
    if (res > 0)
        my_put_nbr_base(res, base);
    my_putchar(base[rest]);
    return (0);
}