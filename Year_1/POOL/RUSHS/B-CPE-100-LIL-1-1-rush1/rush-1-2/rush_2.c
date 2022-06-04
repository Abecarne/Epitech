/*
** EPITECH PROJECT, 2020
** Anthony Becarne et Antoine Paul
** File description:
** rush numero 1
*/

int one_line_2(int x, int y)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            my_putchar('*'); 
        }
        my_putchar('\n');
    }
}

int print_2(int x, int y)
{
    top_2(x);
    for (int i = 0; i < y - 2; i++) {
        middle_2(x);
    }
    if (y != 1) {
        bottom_2(x);
    }
}

int top_2(int larg) 
{
    for (int i = 0; i < larg; i++) {
        if (i == 0) {
            my_putchar('/');
        } else if (i == larg - 1) {
            my_putchar(92);
        } else {
            my_putchar('*');
        }
    }
    my_putchar('\n');
}

int middle_2(int y)
{
    if (y == 1) {
        my_putchar('*'); 
    } else if (y > 1) {
        my_putchar('*');
        for (int i = 0; i < y - 2; i++) {
            my_putchar(' ');
        }
    my_putchar('*');
    }
    my_putchar('\n');   
}

int bottom_2(int x)
{
    for (int i = 0; i < x; i++) {
        if (i == 0) {
            my_putchar(92);
        } else if (i == x - 1) {
            my_putchar('/');
        } else {
            my_putchar('*');
        }
    }
    my_putchar('\n');
}