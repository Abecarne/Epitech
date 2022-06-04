/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_print_comb
*/

void my_putchar(char c);

int display(char a, char b, char c)
{
    if (a == '7' && b == '8' && c == '9') {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
    } else {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb(void)
{
    int a = '0';
    int b = '1';
    int c = '2';

    while (a <= '7') {
        b = a + 1;
        while (b <= '8') {
            c = b + 1;
            while (c <= '9') {
                display(a,b,c);
                c++;
            }
            b++;
        }
        a++;
    }
    my_putchar('\n');
}

