/*
** EPITECH PROJECT, 2020
** Anthony Becarne et Antoine Paul
** File description:
** rush numero 1
*/

int one_line_4(int x, int y)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            my_putchar('B');
        }
        my_putchar('\n');
    }
}

int print_4(int x, int y)
{
    top_4(x);
    for (int i = 0; i < y - 2; i++) {
        middle_4(x);
    }
    if (y != 1) {
        bottom_4(x);
    }
}

void top_4(int larg) 
{
    for (int i = 0; i < larg; i++) {
        if (i == 0) {
            my_putchar('A');
        } else if (i == larg - 1) {
            my_putchar('C');
        } else {
            my_putchar('B');
        }
    }
    my_putchar('\n');
}

void middle_4(int y)
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

void bottom_4(int x)
{
    for (int i = 0; i < x; i++) {
        if (i == 0) {
            my_putchar('A');
        } else if (i == x - 1) {
            my_putchar('C');
        } else {
            my_putchar('B');
        }
    }
    my_putchar('\n');
}