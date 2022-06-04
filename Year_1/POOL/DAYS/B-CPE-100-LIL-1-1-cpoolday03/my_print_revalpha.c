/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_print_revalpha
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    int i = 'z';
    for (i; i >= 'a'; i--) {
        my_putchar(i);
    }
    my_putchar('\n');
    return (0);
}