/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Task 04
*/

char my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}
