/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Task 03
*/

void my_swap(char *a, char *b);

char *my_revstr(char *str)
{
    int length = 0;
    int a = 0;

    for (int length = 0; str[length] != '\0'; ++length)
        a = length;
    for (int b = 0; b <= a; ++b) {
        my_swap(&str[b], &str[a]);
        --a;
    }
    return (str);
}
