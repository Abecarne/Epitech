/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** My_isneg
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}

int my_str_isnbr(char *s1)
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] < 48 || s1[i] > 57 || s1[i] == '-' || s1[i] == '+')
            return (1);
    return (0);
}