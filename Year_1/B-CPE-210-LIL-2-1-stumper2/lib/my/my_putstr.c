/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Task 02
*/

void my_putchar(char c);

void my_putchar_error(char c);

int my_putstr(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar(str[a]);
    a = a + 1;
    }
}

int my_putstr_error(char const *str)
{
    int a = 0;

    while (str[a] != '\0') {
        my_putchar_error(str[a]);
        a = a + 1;
    }
    return (84);
}

void my_put_tab(char **tab)
{
    while (*tab) {
        my_putstr(*tab);
        tab++;
    }
}