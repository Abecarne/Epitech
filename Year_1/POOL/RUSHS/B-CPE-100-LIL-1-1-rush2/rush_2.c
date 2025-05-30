/*
** EPITECH PROJECT, 2020
** Anthony Becarne & Noa Chambrin
** File description:
** rush_1
*/

#include <stddef.h>
#include <stdlib.h>

int my_strlen(char  const *str);

void my_putchar(char c);

int  my_put_nbr(int nb);

void display2(char c, int nb)
{
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(nb);
    my_putchar('\n');
}

int cpt_letters2(char *str, char a)
{
    int cpt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == a) || (str[i] == a - 32) || (str[i] == a + 32)) {
            cpt++;
        }
    }
    return (cpt);
}

void nb_letters2(int argc, char **argv)
{
    char *str = argv[1];
    int nb_let = 0;
    char letter;

    for (int i = 2; i < argc; i++) {
        letter = argv[i][0];
        if (letter != (!(letter >= 'a' && letter <= 'z')
        || (letter >= 'A' && letter <= 'Z'))) {
            write(2, "Invalid char\n", 13);
    }
        nb_let = cpt_letters2(str, letter);
        display2(letter, nb_let);
    }
}
