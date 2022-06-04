/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday05-simon.auduberteau
** File description:
** my_compute_square_root
*/

int  my_compute_square_root(int nb)
{
    int tmp = 1;

    if (nb < 0 || nb == 0)
        return (0);
    if (nb == 1)
        return (1);
    for (int i = 1; i <= 46341; i++) {
        tmp = i;
        tmp *= tmp;
        if (tmp == nb)
            return (i);
    }
    return (0);
}