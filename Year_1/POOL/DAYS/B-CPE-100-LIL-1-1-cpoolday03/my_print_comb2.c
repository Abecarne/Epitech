/*
** EPITECH PROJECT, 2020
** Anthony Becarne
** File description:
** my_print_comb deuxième du nom
*/
void my_putchar(char c);

int display2(int a)
{
    char part1 = a / 10 + 48;
    char part2 = a % 10 + 48;

    my_putchar(part1);
    my_putchar(part2);
}

int my_print_comb2(void)
{
    int a = 0;
    int b = 1;
    while (a < b) {
        while(b < 100) {
            if (a == 98) {
                display2(a);
                my_putchar(' ');
                display2(b);
            } else {
                display2(a);
                my_putchar(' ');
                display2(b);
                my_putchar(',');
                my_putchar(' ');
            }
            b++;
        }
        a++;
        b = a + 1;
    }
}