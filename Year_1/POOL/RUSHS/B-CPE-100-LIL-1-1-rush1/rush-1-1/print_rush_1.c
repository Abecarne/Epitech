/*
** EPITECH PROJECT, 2020
** Anthony Becarne et Antoine Paul
** File description:
** rush numero 1
*/
int print(int x, int y);
int top(int larg);
int middle(int y);
int bottom(int x);

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
    } else {
        print(x, y);
    }
}