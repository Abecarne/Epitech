/*
** EPITECH PROJECT, 2020
** Anthony Becarne et Antoine Paul
** File description:
** rush numero 1
*/

int one_line_4(int x, int y);
int print_4(int x, int y);
int top_4(int larg);
int middle_4(int y);
int bottom_4(int x);

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
    } else if (x == 1 || y == 1) {
        one_line_4(x, y);
    } else {
        print_4(x, y);
    }
}