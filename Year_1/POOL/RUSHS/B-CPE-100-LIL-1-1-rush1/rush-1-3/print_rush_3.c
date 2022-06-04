/*
** EPITECH PROJECT, 2020
** Anthony Becarne et Antoine Paul
** File description:
** rush numero 1
*/
int one_line_3(int x, int y);
int print_3(int x, int y);
int top_3(int larg);
int middle_3(int y);
int bottom_3(int x);

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
    } else if (x == 1 || y == 1) {
        one_line_3(x, y);
    } else {
        print_3(x, y);
    }
}