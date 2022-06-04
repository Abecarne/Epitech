/*
** EPITECH PROJECT, 2020
** B-PSU-100-LIL-1-1-myprintf-simon.auduberteau
** File description:
** my_put_long
*/

void my_putchar(char c);

long my_put_long(long nb)
{
    long a;

    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0)
    {
        if (nb >= 10)
        {
            a = (nb % 10);
            nb = (nb - a) / 10;
            my_put_long(nb);
            my_putchar(48 + a);
        }
        else
            my_putchar(48 + nb % 10);
    }
}