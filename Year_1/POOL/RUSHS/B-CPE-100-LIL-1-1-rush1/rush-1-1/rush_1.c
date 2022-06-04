/*
** EPITECH PROJECT, 2020
** Anthony Becarne et Antoine Paul
** File description:
** rush numero 1
*/

int print(int x, int y)
{
    top(x);
    for (int i = 0; i < y - 2; i++) {
        middle(x);
    }
    if (y != 1) {
        bottom(x);
    }
}

int top(int larg)
{
    for (int i = 0; i < larg; i++) {
        if (i == 0 || i == larg - 1) {
            my_putchar('o');
        } else {
            my_putchar('-');
        }
    }
    my_putchar('\n');
}

int middle(int y)
{
    if (y == 1) {
        my_putchar('|'); 
    } else if (y > 1) {
        my_putchar('|');
        for (int i = 0; i < y - 2; i++) {
            my_putchar(' ');
        }
    my_putchar('|');
    }
    my_putchar('\n');
}

int bottom(int x)
{
    for (int i = 0; i < x; i++) {
        if (i == 0 || i == x - 1) {
            my_putchar('o');
        } else {
            my_putchar('-');
        }
    }
    my_putchar('\n');
}