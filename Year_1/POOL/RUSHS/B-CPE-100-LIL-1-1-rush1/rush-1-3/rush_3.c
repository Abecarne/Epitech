/*
** EPITECH PROJECT, 2020
** Anthony Becarne et Antoine Paul
** File description:
** rush numero 1
*/

int one_line_3(int x, int y)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            my_putchar('B');
        }
        my_putchar('\n');
    }
}

int print_3(int x, int y)
{
    top_3(x);
    for (int i = 0; i < y - 2; i++) {
        middle_3(x);
    }
    if (y != 1) {
        bottom_3(x);
    }
}

void top_3(int larg) 
{
    for (int i = 0; i < larg; i++) {
        if (i == 0 || i == larg - 1) {
            my_putchar('A');
        } else {
            my_putchar('B');
        }
    }
    my_putchar('\n');
}

void middle_3(int y)
{
    if (y == 1) {
        my_putchar('B'); 
    } else if (y > 1) {
        my_putchar('B');
        for (int i = 0; i < y - 2; i++) {
            my_putchar(' ');
        }
    my_putchar('B');
    }
    my_putchar('\n');   
}

void bottom_3(int x)
{
    for (int i = 0; i < x; i++) {
        if (i == 0 || i == x - 1) {
            my_putchar('C');
        } else {
            my_putchar('B');
        }
    }
    my_putchar('\n');
}
