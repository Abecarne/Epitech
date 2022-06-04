/*
** EPITECH PROJECT, 2020
** Anthony Becarne 
** File description:
** my_print_alpha
*/

int my_print_alpha(void)
{
    int i = 'a';
    for (i; i <= 'z'; i++) {
        my_putchar(i);
    }
    my_putchar('\n');
    return 0;
}