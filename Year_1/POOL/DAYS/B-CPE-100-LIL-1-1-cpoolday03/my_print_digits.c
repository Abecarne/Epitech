/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_print_digits
*/

void my_putchar(char c);

int my_print_digits(void)
{
    for (int i = '0'; i <= '9'; i++) {
        my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}