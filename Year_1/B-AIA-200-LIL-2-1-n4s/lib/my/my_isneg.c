/*
** EPITECH PROJECT, 2020
** B-CPE-100-LIL-1-1-cpoolday03-simon.auduberteau
** File description:
** my_isneg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    my_putchar('\n');
    return (0);
}